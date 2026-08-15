---
강의 수: 6
상태: 완료
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
# 컨테이너 클래스를 만들며 다시 확인한 것
## 생성자
- 생성자의 괄호 안에는 객체 이름이 아니라 외부에서 전달받을 값이 들어간다.
- 생성 중인 객체는 따로 전달하지 않아도 내부적으로 **this**를 통해 알 수 있다.
- 기본 생성자, 길이 생성자, initializer-list 생성자는 각각 빈 객체, 지정된 길이, 여러 값을 가진 객체를 만든다.
- **new int(length)**는 값이 length인 정수 한 개이고, **new int\[length\]**는 정수 length개다.
## initializer-list
- 여러 값을 중괄호로 받으려면 **std::initializer_list\<int\>** 생성자가 필요하다.
- initializer-list는 값들을 직접 소유하지 않고 임시 목록을 바라본다.
- 목록의 주소를 보관하지 않고 값을 **m_data**로 복사해야 한다.
- 소괄호의 5는 길이 5, 중괄호의 5는 값 5 하나로 해석될 수 있다.
## 소멸자와 reset
- 소멸자에는 멤버 초기화 리스트를 사용할 수 없다. **delete\[\]** 같은 실행문은 몸체에 작성한다.
- **new\[\]**로 할당했다면 반드시** delete\[\]**로 해제해야 한다.
- 포인터에 **nullptr**만 대입하면 메모리는 해제되지 않고 주소만 잃어버려 메모리 누수가 생긴다.
- 소멸자는 객체의 수명이 끝날 때 자원을 정리한다.
- **reset**은 자원을 정리한 뒤 같은 객체를 빈 상태로 계속 사용할 수 있게 한다.
## 포인터
- *intArray ptr = &arr*에서 **&arr**는 arr 객체 전체의 주소다.
- **new_data**는 새 배열 주소를 임시로 보관하는 지역 포인터 변수다.
- 해제된 메모리 주소를 계속 가지고 있는 포인터는 댕글링 포인터.
## 💻 코드 스니펫
```cpp
class intArray
{
private:
    int m_length;
    int* m_data;

public:
    // Constructos
    intArray()
        : m_length(0), m_data(nullptr)
    {}

    intArray(const int length)
        : m_length(length),
        m_data(new int[length]{})
    {}

    intArray(const std::initializer_list<int>& list)
        : intArray()
    {
        initialize(static_cast<int>(list.size()));
        int index = 0;

        for (const int value : list)
        {
            m_data[index] = value;
            ++index;
        }
    }

    // Destructors
    ~intArray() { delete[] m_data; }

    // reset
    void reset()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    // initialize()
    void initialize(const int length)
    {
        reset();

        if (length <= 0)
            return;

        m_data = new int[length] {};
        m_length = length;
    }

    // insertBefore
    void insertBefore(const int& value, const int& ix)
    {
        if (ix <0 || ix > m_length)
            return;

        int* new_data = new int[m_length + 1] {};
        for (int i = 0; i < ix; ++i) { new_data[i] = m_data[i]; }
        new_data[ix] = value;
        for (int i = ix; i < m_length; ++i ) { new_data[i + 1] = m_data[i]; }

        delete[] m_data;
        m_data = new_data;
        m_length += 1;
    }

    // remove(const int & ix);
    void remove(const int& ix)
    {
        if (ix <0 || ix >= m_length)
            return;

        if (m_length == 1)
        {
            reset();
            return;
        }

        int* new_data = new int[m_length - 1] {};
        for (int i = 0; i < ix; ++i) { new_data[i] = m_data[i]; }
        for (int i = ix + 1; i < m_length; ++i) { new_data[i - 1] = m_data[i]; }

        delete[] m_data;
        m_data = new_data;
        m_length -= 1;
    }

    //push_back
    void push_back(const int& value)
    {
        insertBefore(value, m_length);
    }

    //print
    void print() const
    {
        for (int i = 0; i < m_length; ++i)
        {
            cout << m_data[i] << ' ';
        }

        cout << '\n';
    }

};
```
## 🔥 헷갈린 것들 / 질문
-
## ✅ 복습 체크
- [x] 강의 완주
- [x] 코드 직접 따라 침
- [x] 복습 1회
- [ ] 복습 2회 (OOP 핵심 섹션은 2회 복습)
