# Notion 학습 노트 내보내기

Notion 데이터베이스의 학습 노트를 `notes/notion/` 아래 표준 Markdown으로 백업하는 로컬 전용 도구입니다.

## 보안 원칙

- ChatGPT/Codex MCP에는 Notion을 연결하지 않습니다.
- Notion 내부 연결에는 `Read content` 권한만 부여합니다.
- 내부 연결은 내보낼 학습 데이터베이스에만 추가합니다.
- 토큰은 저장소가 아닌 `%APPDATA%\TBCppStudy`에 Windows DPAPI 암호화 상태로 저장됩니다.
- 토큰이나 `.env` 파일은 Git에 커밋하지 않습니다.

## 최초 설정

1. Notion에서 읽기 전용 내부 연결을 만듭니다.
2. 학습 노트 데이터베이스의 `Connections`에 그 연결을 추가합니다.
3. PowerShell에서 다음을 실행하고 데이터베이스 URL과 토큰을 로컬 창에 입력합니다.

```powershell
.\scripts\notion\Set-NotionExportConfig.ps1
```

토큰은 화면에 표시되지 않으며 채팅에 붙여넣지 않습니다.

## 내보내기

```powershell
.\scripts\notion\Export-NotionNotes.ps1
```

내보내기 도구는 다음 작업을 수행합니다.

- 데이터베이스 속성을 YAML frontmatter로 보존 (`학습 기록` 관계 속성은 제외)
- 본문을 Markdown으로 변환
- 페이지 제목이 본문에 없으면 H1 제목 추가
- 원격 이미지를 `notes/notion/assets/`에 내려받고 상대 링크로 변경
- 섹션 번호 순서의 노트 목록 생성
- 내용이 동일한 파일은 다시 쓰지 않아 불필요한 Git 변경 방지

`학습 기록`은 공부 내용과 중복되는 관리용 관계 속성이어서 기본 제외합니다. 다른 속성도 빼고 싶다면 `%APPDATA%\TBCppStudy\notion-export.json`의 `excluded_properties` 목록에 이름을 추가하면 됩니다.

## 커밋

저장소 루트의 `.\study.ps1`을 실행하면 Notion 내보내기부터 커밋·푸시까지 한 번에 진행합니다. 자동 제안된 커밋 메시지와 대상 파일을 최종 확인하므로, 원하지 않는 변경이 올라가는 것을 막을 수 있습니다.

저장소가 공개되어 있으므로 개인 정보나 공개하면 안 되는 Notion 내용이 포함되지 않았는지 먼저 확인합니다.
