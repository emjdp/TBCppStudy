[CmdletBinding()]
param(
    [string]$ConfigPath = (Join-Path $env:APPDATA "TBCppStudy\notion-export.json")
)

$ErrorActionPreference = "Stop"
$utf8NoBom = [Text.UTF8Encoding]::new($false)
Add-Type -AssemblyName System.Net.Http

function Invoke-Ntn {
    param(
        [Parameter(Mandatory)][string]$Executable,
        [Parameter(Mandatory)][string[]]$Arguments
    )

    $startInfo = [Diagnostics.ProcessStartInfo]::new()
    $startInfo.FileName = $Executable
    $startInfo.UseShellExecute = $false
    $startInfo.RedirectStandardOutput = $true
    $startInfo.RedirectStandardError = $true
    $startInfo.StandardOutputEncoding = [Text.UTF8Encoding]::new($false)
    $startInfo.StandardErrorEncoding = [Text.UTF8Encoding]::new($false)
    $startInfo.Arguments = (($Arguments | ForEach-Object { '"' + $_.Replace('"', '\"') + '"' }) -join " ")

    $process = [Diagnostics.Process]::new()
    $process.StartInfo = $startInfo
    [void]$process.Start()
    $stdoutTask = $process.StandardOutput.ReadToEndAsync()
    $stderrTask = $process.StandardError.ReadToEndAsync()
    $process.WaitForExit()
    $stdout = $stdoutTask.GetAwaiter().GetResult()
    $stderr = $stderrTask.GetAwaiter().GetResult()

    if ($process.ExitCode -ne 0) {
        throw "ntn 명령이 실패했습니다: $stderr"
    }
    if ($stderr -match "truncated") {
        throw "Notion 페이지가 잘려서 반환됐습니다. 페이지를 나누거나 unknown_block_ids 처리를 추가해야 합니다."
    }

    return $stdout
}

function Get-PageTitle {
    param([Parameter(Mandatory)]$Page)

    foreach ($property in $Page.properties.PSObject.Properties) {
        if ($property.Value.type -eq "title") {
            return (($property.Value.title | ForEach-Object { $_.plain_text }) -join "").Trim()
        }
    }
    return "Untitled"
}

function Get-NumberProperty {
    param(
        [Parameter(Mandatory)]$Page,
        [Parameter(Mandatory)][string]$Name
    )

    $property = $Page.properties.PSObject.Properties[$Name]
    if (-not $property) { return $null }
    if ($property.Value.type -eq "number") { return $property.Value.number }
    if ($property.Value.type -eq "formula" -and $property.Value.formula.type -eq "number") {
        return $property.Value.formula.number
    }
    return $null
}

function Get-LabelProperty {
    param(
        [Parameter(Mandatory)]$Page,
        [Parameter(Mandatory)][string]$Name
    )

    $property = $Page.properties.PSObject.Properties[$Name]
    if (-not $property) { return "" }
    switch ($property.Value.type) {
        "status" { return [string]$property.Value.status.name }
        "select" { return [string]$property.Value.select.name }
        "checkbox" { return $(if ($property.Value.checkbox) { "완료" } else { "미완료" }) }
        default { return "" }
    }
}

function Get-SafeSlug {
    param([Parameter(Mandatory)][string]$Value)

    $slug = $Value.Trim().ToLowerInvariant()
    $slug = $slug -replace '[<>:"/\\|?*]', ""
    $slug = $slug -replace "\s+", "-"
    $slug = $slug -replace "-+", "-"
    $slug = $slug.Trim("-", ".")
    if (-not $slug) { return "untitled" }
    if ($slug.Length -gt 60) { return $slug.Substring(0, 60).TrimEnd("-") }
    return $slug
}

function Get-ExtensionFromMediaType {
    param(
        [string]$MediaType,
        [string]$Url
    )

    $knownTypes = @{
        "image/png" = ".png"
        "image/jpeg" = ".jpg"
        "image/gif" = ".gif"
        "image/webp" = ".webp"
        "image/svg+xml" = ".svg"
        "image/bmp" = ".bmp"
        "image/tiff" = ".tiff"
        "image/avif" = ".avif"
    }
    if ($MediaType -and $knownTypes.ContainsKey($MediaType.ToLowerInvariant())) {
        return $knownTypes[$MediaType.ToLowerInvariant()]
    }

    try {
        $extension = [IO.Path]::GetExtension(([Uri]$Url).AbsolutePath).ToLowerInvariant()
        if ($extension -match '^\.(png|jpe?g|gif|webp|svg|bmp|tiff?|avif)$') {
            return $extension
        }
    }
    catch { }
    return ".bin"
}

function Write-BytesIfChanged {
    param(
        [Parameter(Mandatory)][string]$Path,
        [Parameter(Mandatory)][byte[]]$Bytes
    )

    if (Test-Path -LiteralPath $Path) {
        $existing = [IO.File]::ReadAllBytes($Path)
        if ($existing.Length -eq $Bytes.Length) {
            $same = $true
            for ($index = 0; $index -lt $Bytes.Length; $index++) {
                if ($existing[$index] -ne $Bytes[$index]) { $same = $false; break }
            }
            if ($same) { return }
        }
    }
    [IO.File]::WriteAllBytes($Path, $Bytes)
}

function Save-RemoteImages {
    param(
        [Parameter(Mandatory)][string]$Markdown,
        [Parameter(Mandatory)][string]$OutputDirectory,
        [Parameter(Mandatory)][string]$PageId
    )

    $pattern = '!\[(?<alt>[^\]]*)\]\((?:<)?(?<url>https?://[^)>\s]+)(?:>)?(?<suffix>\s+(?:"[^"]*"|''[^'']*''))?\)'
    $matches = @([regex]::Matches($Markdown, $pattern))
    if ($matches.Count -eq 0) { return $Markdown }

    $assetFolderName = $PageId.Replace("-", "").ToLowerInvariant()
    $assetDirectory = Join-Path $OutputDirectory (Join-Path "assets" $assetFolderName)
    New-Item -ItemType Directory -Path $assetDirectory -Force | Out-Null
    $httpClient = [Net.Http.HttpClient]::new()
    $httpClient.DefaultRequestHeaders.UserAgent.ParseAdd("TBCppStudy-Notion-Exporter/1.0")

    $replacements = [Collections.Generic.List[object]]::new()
    try {
        for ($index = 0; $index -lt $matches.Count; $index++) {
            $match = $matches[$index]
            $url = $match.Groups["url"].Value
            try {
                $response = $httpClient.GetAsync($url).GetAwaiter().GetResult()
                [void]$response.EnsureSuccessStatusCode()
                $bytes = $response.Content.ReadAsByteArrayAsync().GetAwaiter().GetResult()
                $mediaType = [string]$response.Content.Headers.ContentType.MediaType
                $extension = Get-ExtensionFromMediaType -MediaType $mediaType -Url $url
                $fileName = "image-{0:D2}{1}" -f ($index + 1), $extension
                $filePath = Join-Path $assetDirectory $fileName
                Write-BytesIfChanged -Path $filePath -Bytes $bytes

                $relativePath = "assets/$assetFolderName/$fileName"
                $replacement = "![$($match.Groups['alt'].Value)]($relativePath$($match.Groups['suffix'].Value))"
                $replacements.Add([pscustomobject]@{
                    Index = $match.Index
                    Length = $match.Length
                    Text = $replacement
                })
            }
            catch {
                Write-Warning "이미지를 내려받지 못해 원본 링크를 유지합니다: $url ($($_.Exception.Message))"
            }
        }
    }
    finally {
        $httpClient.Dispose()
    }

    foreach ($replacement in ($replacements | Sort-Object Index -Descending)) {
        $Markdown = $Markdown.Remove($replacement.Index, $replacement.Length).Insert($replacement.Index, $replacement.Text)
    }
    return $Markdown
}

function Add-TitleIfMissing {
    param(
        [Parameter(Mandatory)][string]$Markdown,
        [Parameter(Mandatory)][string]$Title
    )

    if ($Markdown -match '(?m)^#\s+') { return $Markdown }
    if ($Markdown.StartsWith("---")) {
        $frontmatterEnd = $Markdown.IndexOf("`n---", 3)
        if ($frontmatterEnd -ge 0) {
            $insertAt = $frontmatterEnd + 4
            return $Markdown.Insert($insertAt, "`n`n# $Title")
        }
    }
    return "# $Title`n`n$Markdown"
}

function Remove-ExcludedFrontmatterProperties {
    param(
        [Parameter(Mandatory)][string]$Markdown,
        [string[]]$Names = @()
    )

    if ($Names.Count -eq 0 -or -not $Markdown.StartsWith("---`n")) {
        return $Markdown
    }

    $lines = [regex]::Split($Markdown, "`n")
    $frontmatterEnd = -1
    for ($index = 1; $index -lt $lines.Count; $index++) {
        if ($lines[$index] -eq "---") {
            $frontmatterEnd = $index
            break
        }
    }
    if ($frontmatterEnd -lt 0) { return $Markdown }

    $excluded = @{}
    foreach ($name in $Names) {
        if (-not [string]::IsNullOrWhiteSpace($name)) {
            $excluded[$name.Trim()] = $true
        }
    }

    $result = [Collections.Generic.List[string]]::new()
    $result.Add($lines[0])
    $skipProperty = $false
    for ($index = 1; $index -lt $frontmatterEnd; $index++) {
        $line = $lines[$index]
        if ($line -match '^(?<name>[^\s:#][^:]*):(?:\s.*)?$') {
            $skipProperty = $excluded.ContainsKey($Matches["name"].Trim())
        }
        if (-not $skipProperty) {
            $result.Add($line)
        }
    }
    for ($index = $frontmatterEnd; $index -lt $lines.Count; $index++) {
        $result.Add($lines[$index])
    }

    return $result -join "`n"
}

function Normalize-NotionMarkdown {
    param([Parameter(Mandatory)][string]$Markdown)

    $Markdown = [regex]::Replace($Markdown, '(?m)^```c\+\+\s*$', '```cpp')
    $Markdown = [regex]::Replace($Markdown, '(?m)^\s*<empty-block\s*/>\s*\n?', '')
    $Markdown = [regex]::Replace($Markdown, '(?m)[\t ]+$', '')
    return $Markdown
}

function Write-TextIfChanged {
    param(
        [Parameter(Mandatory)][string]$Path,
        [Parameter(Mandatory)][string]$Content
    )

    $Content = $Content.Replace("`r`n", "`n").Replace("`r", "`n").TrimEnd() + "`n"
    if ((Test-Path -LiteralPath $Path) -and ([IO.File]::ReadAllText($Path) -ceq $Content)) {
        return
    }
    [IO.File]::WriteAllText($Path, $Content, $script:utf8NoBom)
}

function Get-NtnExecutable {
    $command = Get-Command ntn -ErrorAction SilentlyContinue
    if (-not $command) { return $null }
    if ([IO.Path]::GetExtension($command.Source) -eq ".exe") { return $command.Source }

    $npmDirectory = Split-Path -Parent $command.Source
    $nativeExecutable = Join-Path $npmDirectory "node_modules\ntn\bin\ntn.exe"
    if (Test-Path -LiteralPath $nativeExecutable) { return $nativeExecutable }
    return $null
}

if (-not (Test-Path -LiteralPath $ConfigPath)) {
    throw "설정 파일이 없습니다: $ConfigPath`n먼저 Set-NotionExportConfig.ps1을 실행하세요."
}
$config = Get-Content -LiteralPath $ConfigPath -Raw | ConvertFrom-Json
$notionVersion = if ($config.notion_version) { [string]$config.notion_version } else { "2026-03-11" }
$excludedProperties = if ($config.PSObject.Properties.Name -contains "excluded_properties") {
    @($config.excluded_properties | ForEach-Object { [string]$_ })
}
else {
    @("학습 기록")
}
if (-not (Test-Path -LiteralPath $config.token_path)) {
    throw "암호화된 Notion 토큰을 찾지 못했습니다: $($config.token_path)"
}

$ntnExecutable = Get-NtnExecutable
if (-not $ntnExecutable) {
    throw "공식 Notion CLI(ntn)를 찾지 못했습니다."
}

$repositoryRoot = (Resolve-Path (Join-Path $PSScriptRoot "..\..")).Path
$outputDirectory = Join-Path $repositoryRoot $config.output_relative_path
New-Item -ItemType Directory -Path $outputDirectory -Force | Out-Null

$encryptedToken = (Get-Content -LiteralPath $config.token_path -Raw).Trim()
$secureToken = ConvertTo-SecureString $encryptedToken
$tokenPointer = [IntPtr]::Zero
$previousToken = $env:NOTION_API_TOKEN

try {
    $tokenPointer = [Runtime.InteropServices.Marshal]::SecureStringToBSTR($secureToken)
    $plainToken = [Runtime.InteropServices.Marshal]::PtrToStringBSTR($tokenPointer)
    $env:NOTION_API_TOKEN = $plainToken

    $queryJson = Invoke-Ntn -Executable $ntnExecutable -Arguments @(
        "datasources", "query", [string]$config.data_source_id, "--limit", "1000", "--json",
        "--notion-version", $notionVersion
    )
    $query = $queryJson | ConvertFrom-Json
    $pages = if ($query -is [array]) { @($query) } elseif ($query.results) { @($query.results) } else { @() }
    if ($pages.Count -eq 0) {
        throw "내보낼 Notion 페이지를 찾지 못했습니다."
    }

    $indexRows = [Collections.Generic.List[object]]::new()
    $usedNames = @{}
    foreach ($page in $pages) {
        $pageId = [string]$page.id
        $title = Get-PageTitle -Page $page
        $order = Get-NumberProperty -Page $page -Name ([string]$config.order_property)
        $status = Get-LabelProperty -Page $page -Name ([string]$config.status_property)
        $slug = Get-SafeSlug -Value $title

        if ($null -ne $order) {
            $fileName = "section-{0:D2}.md" -f [int]$order
        }
        else {
            $fileName = "$slug-$($pageId.Replace('-', '').Substring(0, 8)).md"
        }
        if ($usedNames.ContainsKey($fileName)) {
            $fileName = "$([IO.Path]::GetFileNameWithoutExtension($fileName))-$($pageId.Replace('-', '').Substring(0, 8)).md"
        }
        $usedNames[$fileName] = $true

        Write-Host "내보내는 중: $title -> $fileName"
        $markdown = Invoke-Ntn -Executable $ntnExecutable -Arguments @(
            "pages", "get", $pageId, "--notion-version", $notionVersion
        )
        $markdown = $markdown.Replace("`r`n", "`n").Replace("`r", "`n")
        $markdown = Remove-ExcludedFrontmatterProperties -Markdown $markdown -Names $excludedProperties
        $markdown = Add-TitleIfMissing -Markdown $markdown -Title $title
        $markdown = Normalize-NotionMarkdown -Markdown $markdown
        $markdown = Save-RemoteImages -Markdown $markdown -OutputDirectory $outputDirectory -PageId $pageId
        Write-TextIfChanged -Path (Join-Path $outputDirectory $fileName) -Content $markdown

        $indexRows.Add([pscustomobject]@{
            Order = if ($null -ne $order) { [double]$order } else { [double]::PositiveInfinity }
            Title = $title.Replace("|", "\|")
            Status = $status.Replace("|", "\|")
            FileName = $fileName
        })
    }

    $indexLines = [Collections.Generic.List[string]]::new()
    $indexLines.Add("# Notion 학습 노트")
    $indexLines.Add("")
    $indexLines.Add("Notion에서 작성하고 로컬 내보내기 도구로 Markdown 백업한 학습 노트입니다.")
    $indexLines.Add("")
    $indexLines.Add("| 섹션 | 상태 |")
    $indexLines.Add("|---|---|")
    foreach ($row in ($indexRows | Sort-Object Order, Title)) {
        $indexLines.Add("| [$($row.Title)]($($row.FileName)) | $($row.Status) |")
    }
    Write-TextIfChanged -Path (Join-Path $outputDirectory "README.md") -Content ($indexLines -join "`n")

    Write-Host ""
    Write-Host "내보내기 완료: $outputDirectory" -ForegroundColor Green
}
finally {
    if ($null -eq $previousToken) {
        Remove-Item Env:NOTION_API_TOKEN -ErrorAction SilentlyContinue
    }
    else {
        $env:NOTION_API_TOKEN = $previousToken
    }
    if ($tokenPointer -ne [IntPtr]::Zero) {
        [Runtime.InteropServices.Marshal]::ZeroFreeBSTR($tokenPointer)
    }
    $plainToken = $null
}
