<div align="center">

# TBCppStudy

따라 하며 이해하고, 직접 실행하며 기록하는 C++ 학습 저장소입니다.

![C++ Study](https://img.shields.io/badge/C%2B%2B-Study-00599C?style=for-the-badge&logo=cplusplus&logoColor=white&labelColor=0d1117)
![Visual Studio](https://img.shields.io/badge/Visual%20Studio-2026-5C2D91?style=for-the-badge&logo=visualstudio&logoColor=white&labelColor=0d1117)
![Last commit](https://img.shields.io/github/last-commit/emjdp/TBCppStudy?style=for-the-badge&logo=github&labelColor=0d1117&color=238636)

</div>

> **현재 진도:** 섹션 1 완료 · 섹션 2 진행 중
>
> 기록은 공부를 돕는 수단으로만 사용하고, 이해하고 직접 구현하는 데 집중합니다.

## Study activity

![TBCppStudy repository study activity](https://raw.githubusercontent.com/emjdp/TBCppStudy/readme-visuals/study-activity.svg)

이 히트맵은 `TBCppStudy` 저장소의 실제 커밋 날짜만 집계합니다. `main`에 푸시할 때와 매일 자정 무렵 자동으로 갱신됩니다.

## Learning notes

Notion에서 작성한 학습 노트를 읽기 전용 로컬 도구로 Markdown 백업합니다. 개인 Notion 토큰은 GitHub나 MCP에 전달하지 않고 Windows 사용자 계정에 암호화해 보관합니다.

- [섹션별 학습 노트와 현재 상태](notes/notion/README.md)
- [Notion 로컬 내보내기 사용법](scripts/notion/README.md)

## Repository structure

```text
TBCppStudy/
├─ Chapter1_1/       # C++ 시작
├─ Chapter2_1~5/     # C++ 기본 사용법 실습
├─ notes/notion/     # Notion에서 백업한 학습 노트
├─ scripts/notion/   # 읽기 전용 로컬 내보내기
└─ TBCppStudy.slnx   # Visual Studio 솔루션
```

## Daily workflow

1. 공부 시작 전 `Git → Pull`
2. 예제를 직접 작성하고 실행 결과 확인
3. Notion 학습 노트 작성
4. `scripts/notion/Export-NotionNotes.ps1` 실행
5. Visual Studio의 Git Changes에서 검토
6. `Commit All and Push`

커밋 메시지는 공부한 내용이 드러나도록 작성합니다.

```text
study: learn variables and initialization
study: practice pointers and references
notes: summarize chapter 3
fix: correct chapter example
```

## GitHub activity

아래 애니메이션은 이 저장소가 아니라 GitHub 계정 전체의 공개 기여 활동을 보여주는 보조 지표입니다.

![GitHub contribution snake](https://raw.githubusercontent.com/emjdp/TBCppStudy/readme-visuals/github-snake.svg)
