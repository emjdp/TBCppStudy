[CmdletBinding()]
param(
    [string]$Message,
    [switch]$SkipNotion,
    [switch]$NoPush,
    [switch]$Yes,
    [switch]$Preview
)

$ErrorActionPreference = "Stop"
Set-StrictMode -Version Latest

function Invoke-Git {
    param(
        [Parameter(Mandatory)][string[]]$Arguments,
        [switch]$Capture
    )

    # Windows PowerShell 5.1 can promote native stderr warnings to terminating
    # errors when ErrorActionPreference is Stop. Capture the real exit code
    # instead so harmless Git warnings do not abort the workflow.
    $previousErrorActionPreference = $ErrorActionPreference
    try {
        $ErrorActionPreference = 'Continue'
        $output = @(& git @Arguments 2>&1)
        $exitCode = $LASTEXITCODE
    }
    finally {
        $ErrorActionPreference = $previousErrorActionPreference
    }

    $standardOutput = @($output | Where-Object { $_ -isnot [Management.Automation.ErrorRecord] })
    $standardError = @($output | Where-Object { $_ -is [Management.Automation.ErrorRecord] } | ForEach-Object { $_.ToString() })

    if ($exitCode -ne 0) {
        throw "git $($Arguments -join ' ') failed:`n$($output -join [Environment]::NewLine)"
    }

    if ($Capture) {
        return $standardOutput
    }
    $standardOutput | ForEach-Object { Write-Host $_ }
    $standardError | ForEach-Object { Write-Warning $_ }
}

function Get-StudyCommitMessage {
    param([Parameter(Mandatory)][string[]]$ChangedFiles)

    $completedSections = [Collections.Generic.HashSet[int]]::new()
    $currentSection = $null
    $noteDiff = @(& git diff HEAD --unified=0 -- notes/notion 2>$null)

    foreach ($line in $noteDiff) {
        if ($line -match '^diff --git a/notes/notion/section-(\d+)\.md ') {
            $currentSection = [int]$Matches[1]
            continue
        }
        if ($null -ne $currentSection -and $line -match '^\+\uC0C1\uD0DC:\s*\uC644\uB8CC\s*$') {
            [void]$completedSections.Add($currentSection)
        }
    }

    if ($completedSections.Count -eq 1) {
        $section = @($completedSections)[0]
        return "study: complete section $section"
    }
    if ($completedSections.Count -gt 1) {
        $sections = @($completedSections) | Sort-Object
        return "study: complete sections $($sections -join ', ')"
    }

    $lessonsByChapter = @{}
    foreach ($file in $ChangedFiles) {
        if ($file -match '^Chapter(\d+)_(\d+)/') {
            $chapter = [int]$Matches[1]
            $lesson = [int]$Matches[2]
            if (-not $lessonsByChapter.ContainsKey($chapter)) {
                $lessonsByChapter[$chapter] = [Collections.Generic.HashSet[int]]::new()
            }
            [void]$lessonsByChapter[$chapter].Add($lesson)
        }
    }

    if ($lessonsByChapter.Count -eq 1) {
        $chapter = @($lessonsByChapter.Keys)[0]
        $lessons = @(@($lessonsByChapter[$chapter]) | Sort-Object)
        if ($lessons.Count -eq 1) {
            return "study: practice chapter $chapter lesson $($lessons[0])"
        }
        return "study: cover chapter $chapter lessons $($lessons[0])-$($lessons[-1])"
    }

    $notionChanged = @($ChangedFiles | Where-Object { $_ -like 'notes/notion/*' }).Count -gt 0
    if ($notionChanged) {
        return "notes: update study notes"
    }
    return "study: update C++ exercises"
}

$repoRoot = $PSScriptRoot
Push-Location $repoRoot
try {
    Invoke-Git -Arguments @('rev-parse', '--is-inside-work-tree') -Capture | Out-Null

    if (-not $SkipNotion) {
        Write-Host "`n[1/4] Exporting Notion notes..." -ForegroundColor Cyan
        & (Join-Path $repoRoot 'scripts\notion\Export-NotionNotes.ps1')
        if ($LASTEXITCODE -ne 0) {
            throw "Notion export failed. Nothing was committed."
        }
    }
    else {
        Write-Host "`n[1/4] Skipping Notion export." -ForegroundColor DarkGray
    }

    $conflicts = @(Invoke-Git -Arguments @('diff', '--name-only', '--diff-filter=U') -Capture)
    if ($conflicts.Count -gt 0) {
        throw "Resolve merge conflicts before finishing the study session:`n$($conflicts -join [Environment]::NewLine)"
    }

    $workingFiles = @(Invoke-Git -Arguments @('ls-files', '--modified', '--others', '--exclude-standard') -Capture)
    $alreadyStagedFiles = @(Invoke-Git -Arguments @('diff', '--cached', '--name-only') -Capture)
    $changedFiles = @($workingFiles + $alreadyStagedFiles | Sort-Object -Unique)
    if ($changedFiles.Count -eq 0) {
        Write-Host "`nNo changes to commit." -ForegroundColor Green
        return
    }

    $suggestedMessage = Get-StudyCommitMessage -ChangedFiles $changedFiles
    Write-Host "`n[2/4] Files to commit:" -ForegroundColor Cyan
    Invoke-Git -Arguments @('status', '--short')
    Write-Host "`nSuggested message: $suggestedMessage" -ForegroundColor Yellow

    if ($Preview) {
        Write-Host "`nPreview only. No files were staged, committed, or pushed." -ForegroundColor Green
        return
    }

    if ([string]::IsNullOrWhiteSpace($Message)) {
        if ($Yes) {
            $Message = $suggestedMessage
        }
        else {
            $enteredMessage = Read-Host 'Commit message (press Enter to accept)'
            if ([string]::IsNullOrWhiteSpace($enteredMessage)) {
                $Message = $suggestedMessage
            }
            else {
                $Message = $enteredMessage.Trim()
            }
        }
    }

    if (-not $Yes) {
        $action = 'commit and push'
        if ($NoPush) { $action = 'commit without pushing' }
        $confirmation = Read-Host "Ready to $action as '$Message'. Continue? [Y/n]"
        if ($confirmation -match '^(?i:n|no)$') {
            Write-Host "Canceled. No files were staged." -ForegroundColor Yellow
            return
        }
    }

    Write-Host "`n[3/4] Committing..." -ForegroundColor Cyan
    Invoke-Git -Arguments @('add', '--all')
    $stagedFiles = @(Invoke-Git -Arguments @('diff', '--cached', '--name-only') -Capture)
    if ($stagedFiles.Count -eq 0) {
        Write-Host "No staged changes to commit." -ForegroundColor Green
        return
    }
    Invoke-Git -Arguments @('commit', '-m', $Message)

    if ($NoPush) {
        Write-Host "`n[4/4] Push skipped. Commit is local only." -ForegroundColor Yellow
        return
    }

    Write-Host "`n[4/4] Pushing..." -ForegroundColor Cyan
    $upstream = @(& git rev-parse --abbrev-ref --symbolic-full-name '@{upstream}' 2>$null)
    if ($LASTEXITCODE -eq 0 -and $upstream.Count -gt 0) {
        Invoke-Git -Arguments @('push')
    }
    else {
        $branch = (Invoke-Git -Arguments @('branch', '--show-current') -Capture | Select-Object -First 1)
        if ([string]::IsNullOrWhiteSpace($branch)) {
            throw "The commit was created, but a detached HEAD cannot be pushed automatically."
        }
        Invoke-Git -Arguments @('push', '--set-upstream', 'origin', $branch)
    }

    $commit = (Invoke-Git -Arguments @('log', '-1', '--format=%h %s') -Capture | Select-Object -First 1)
    Write-Host "`nDone: $commit" -ForegroundColor Green
}
finally {
    Pop-Location
}
