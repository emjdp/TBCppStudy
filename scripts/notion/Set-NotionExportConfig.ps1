[CmdletBinding()]
param(
    [string]$Database,
    [string]$ConfigRoot = (Join-Path $env:APPDATA "TBCppStudy")
)

$ErrorActionPreference = "Stop"
$errorLogPath = Join-Path $ConfigRoot "setup-error.log"

trap {
    New-Item -ItemType Directory -Path $ConfigRoot -Force | Out-Null
    $safeMessage = [string]$_.Exception.Message
    $safeMessage = $safeMessage -replace '(?i)(secret|ntn)_[A-Za-z0-9_-]+', '$1_[REDACTED]'
    $safeMessage = $safeMessage -replace '(?i)Bearer\s+[A-Za-z0-9._-]+', 'Bearer [REDACTED]'
    $logContent = "[{0}] line {1}: {2}" -f (Get-Date -Format "yyyy-MM-dd HH:mm:ss"), $_.InvocationInfo.ScriptLineNumber, $safeMessage
    Set-Content -LiteralPath $errorLogPath -Value $logContent -Encoding utf8

    Write-Host ""
    Write-Host "설정에 실패했습니다." -ForegroundColor Red
    Write-Host $safeMessage -ForegroundColor Yellow
    Write-Host "토큰을 제외한 오류가 다음 위치에 기록됐습니다:"
    Write-Host $errorLogPath
    break
}

function Get-NotionId {
    param([Parameter(Mandatory)][string]$Value)

    $match = [regex]::Match($Value, "(?i)([0-9a-f]{32}|[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12})")
    if (-not $match.Success) {
        throw "Notion database URL or ID에서 32자리 ID를 찾지 못했습니다."
    }

    return $match.Groups[1].Value.Replace("-", "").ToLowerInvariant()
}

function Invoke-NtnJson {
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
        throw $stderr
    }

    return $stdout | ConvertFrom-Json
}

function Get-DataSources {
    param([Parameter(Mandatory)]$Response)

    if ($Response -is [array]) {
        return @($Response)
    }
    if ($Response.PSObject.Properties.Name -contains "data_sources") {
        return @($Response.data_sources)
    }
    if ($Response.PSObject.Properties.Name -contains "results") {
        return @($Response.results)
    }
    if ($Response.PSObject.Properties.Name -contains "id") {
        return @($Response)
    }

    return @()
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

$ntnExecutable = Get-NtnExecutable
if (-not $ntnExecutable) {
    throw "공식 Notion CLI(ntn)를 찾지 못했습니다. 먼저 'npm install --global ntn'을 실행하세요."
}

if (-not $Database) {
    Write-Host "개별 노트가 아니라 섹션 목록이 보이는 원본 데이터베이스 주소를 사용하세요." -ForegroundColor Cyan
    $Database = Read-Host "내보낼 Notion 데이터베이스 URL 또는 ID"
}
$databaseId = Get-NotionId -Value $Database

Write-Host ""
Write-Host "Notion 내부 연결 토큰을 입력하세요." -ForegroundColor Cyan
Write-Host "토큰은 화면에 표시되지 않으며 이 Windows 사용자에게만 복호화 가능한 형태로 저장됩니다."
$secureToken = Read-Host "Internal integration token" -AsSecureString
if ($secureToken.Length -eq 0) {
    throw "토큰이 입력되지 않았습니다."
}

$tokenPointer = [IntPtr]::Zero
$previousToken = $env:NOTION_API_TOKEN
try {
    $tokenPointer = [Runtime.InteropServices.Marshal]::SecureStringToBSTR($secureToken)
    $plainToken = [Runtime.InteropServices.Marshal]::PtrToStringBSTR($tokenPointer)
    $env:NOTION_API_TOKEN = $plainToken

    Write-Host "데이터베이스 접근 권한을 확인하는 중..."
    $resolved = Invoke-NtnJson -Executable $ntnExecutable -Arguments @(
        "datasources", "resolve", $databaseId, "--json", "--notion-version", "2026-03-11"
    )
    $dataSources = @(Get-DataSources -Response $resolved)
    if ($dataSources.Count -eq 0) {
        throw "접근 가능한 데이터 소스를 찾지 못했습니다. Notion에서 데이터베이스에 내부 연결을 추가했는지 확인하세요."
    }

    if ($dataSources.Count -eq 1) {
        $selected = $dataSources[0]
    }
    else {
        Write-Host "여러 데이터 소스가 발견됐습니다."
        for ($index = 0; $index -lt $dataSources.Count; $index++) {
            $name = if ($dataSources[$index].name) { $dataSources[$index].name } else { "(이름 없음)" }
            Write-Host "[$($index + 1)] $name - $($dataSources[$index].id)"
        }
        $selection = [int](Read-Host "사용할 번호")
        if ($selection -lt 1 -or $selection -gt $dataSources.Count) {
            throw "선택한 번호가 올바르지 않습니다."
        }
        $selected = $dataSources[$selection - 1]
    }

    $dataSourceId = [string]$selected.id
    [void](Invoke-NtnJson -Executable $ntnExecutable -Arguments @(
        "datasources", "query", $dataSourceId, "--limit", "1", "--json", "--notion-version", "2026-03-11"
    ))

    New-Item -ItemType Directory -Path $ConfigRoot -Force | Out-Null
    $tokenPath = Join-Path $ConfigRoot "notion-token.txt"
    $configPath = Join-Path $ConfigRoot "notion-export.json"

    $secureToken | ConvertFrom-SecureString | Set-Content -LiteralPath $tokenPath -Encoding utf8
    $config = [ordered]@{
        database_id = $databaseId
        data_source_id = $dataSourceId
        output_relative_path = "notes/notion"
        order_property = "섹션 번호"
        status_property = "상태"
        excluded_properties = @("학습 기록")
        notion_version = "2026-03-11"
        token_path = $tokenPath
    }
    $config | ConvertTo-Json | Set-Content -LiteralPath $configPath -Encoding utf8
    Remove-Item -LiteralPath $errorLogPath -ErrorAction SilentlyContinue

    Write-Host ""
    Write-Host "설정이 완료됐습니다." -ForegroundColor Green
    Write-Host "Config: $configPath"
    Write-Host "Token:  Windows DPAPI로 암호화됨"
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
