---
강의 수: 6
상태: 복습 필요
섹션 번호: 11
섹션명: 섹션 11. 객체들 간의 관계에 대해
완료일:
  end: null
  start: 2026-08-14
  time_zone: null
완료한 강의 수: 6
중요도: ⭐⭐ OOP 핵심
진도율: 100
총 시간: 1시간 20분
---

# 섹션 11. 객체들 간의 관계에 대해

## 📝 핵심 개념 정리
<table header-row="true">
<tr>
<td>관계</td>
<td>관계를 표현하는 동사</td>
<td>예시</td>
</tr>
<tr>
<td>구성(요소)<br>Composition</td>
<td>Part-of</td>
<td>두뇌는 육체의 일부이다.</td>
</tr>
<tr>
<td>집합<br>Aggregation</td>
<td>Has-a</td>
<td>어떤 사람이 자동차를 가지고 있다.</td>
</tr>
<tr>
<td>연계·제휴<br>Association</td>
<td>Uses-a</td>
<td>환자는 의사의 치료를 받는다.<br>의사는 환자로부터 치료비를 받는다.</td>
</tr>
<tr>
<td>의존<br>Dependency</td>
<td>Depends-on</td>
<td>나는 다리가 부러져서 한 달 동안 목발을 짚었다.</td>
</tr>
</table>
<table header-row="true">
<tr>
<td>관계</td>
<td>관계를 표현하는 동사</td>
<td>관계의 형태</td>
<td>다른 클래스에도 속할 수 있는가?</td>
<td>멤버의 존재를 클래스가 관리?</td>
<td>방향성</td>
</tr>
<tr>
<td>구성(요소)<br>Composition</td>
<td>Part-of</td>
<td>전체/부품</td>
<td>No</td>
<td>Yes</td>
<td>단방향</td>
</tr>
<tr>
<td>집합<br>Aggregation</td>
<td>Has-a</td>
<td>전체/부품</td>
<td>Yes</td>
<td>No</td>
<td>단방향</td>
</tr>
<tr>
<td>연계·제휴<br>Association</td>
<td>Uses-a</td>
<td>용도 외엔 무관</td>
<td>Yes</td>
<td>No</td>
<td>단방향 또는 양방향</td>
</tr>
<tr>
<td>의존<br>Dependency</td>
<td>Depends-on</td>
<td>용도 외엔 무관</td>
<td>Yes</td>
<td>Yes</td>
<td>단방향</td>
</tr>
</table>
### 구성 관계 - Monster와 Position2D
Position2D가 Monster의 일부
Chapter11_02.cpp<br>└─ #include "Monster.h"<br>└─ #include "Position.h"
#### Monster.h
```plain text
#pragma once

#include <string>
#include "Position.h"

class Monster
{
private:
    std::string m_name;
    Position2D m_location;  // Monster를 구성하는 위치 객체

public:
    Monster(const std::string name_in, const Position2D& pos_in)
        : m_name(name_in), m_location(pos_in)
    {}

    void moveTo(const Position2D& pos_target)
    {
        m_location.set(pos_target);
    }
};
```
### 집합 관계 - Lecture와 Teacher·Student
`Teacher`와 `Student`는 `Lecture`와 독립적으로 존재하며, 하나의 객체를 여러 강의가 공유할 수 있다. `Lecture`는 객체를 소유하지 않고 주소만 보관한다.
```plain text
// 값으로 보관 → 포인터로 참조
Teacher* teacher;
std::vector<Student*> students;

// 외부에서 생성한 객체를 등록
lec1.assignTeacher(&teacher1);
lec1.registerStudent(&std1);
lec2.registerStudent(&std1);
```
같은 `std1`을 두 강의에 등록했기 때문에 `lec2.study()`로 학생의 지능을 올리면 `lec1`에서도 변경된 값이 보인다. 또한 `Lecture`가 객체를 소유하지 않으므로 소멸자에서 `Teacher`와 `Student`를 삭제하지 않는다.
### 의존 관계 — Worker와 Timer
```plain text
Chapter11_05
├─ Chapter11_05.cpp
│  └─ #include "Worker.h"
├─ Worker.h
│  └─ Worker 클래스와 doSomething() 선언
├─ Worker.cpp
│  ├─ #include "Worker.h"
│  └─ #include "Timer.h"
└─ Timer.h
   └─ #include <iostream>, <chrono> 등
```
#### 의존 방향
```plain text
Chapter11_05.cpp → Worker
Worker.cpp       → Timer
Worker.h         ✕ Timer
```
## 💻 코드 스니펫
```cpp
// 직접 따라 친 코드 중 기억할 것
```
## 🔥 헷갈린 것들 / 질문
-
## ✅ 복습 체크
- [x] 강의 완주
- [x] 코드 직접 따라 침
- [ ] 복습 1회
- [ ] 복습 2회 (OOP 핵심 섹션은 2회 복습)
