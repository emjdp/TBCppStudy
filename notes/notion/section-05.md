---
강의 수: 10
상태: 진행 중
섹션 번호: 5
섹션명: 섹션 5. 변수 범위와 더 다양한 변수들
완료일: null
완료한 강의 수: 3
중요도: ⭐ 중요
진도율: 30
총 시간: 3시간 9분
---

# 섹션 5. 변수 범위와 더 다양한 변수들

## 📝 핵심 개념 정리
```cpp
int g_x; // external linkage
static int g_x; // internal linkage
const int g_x; // X . 초기화 해줘야함.

extern int g_z;
extern const int g_z; // 다른곳에서 초기화 해주면 됨.

int g_y(1);
static int g_y(1); // 외부에서는 못 씀.
const int g_y(1);

extern int g_w(1); // 다른곳에서는 초기화 하면 안 됨.
extern const int g_w(1);
```
```cpp
#pragma once

namespace Constants
{
	extern const double pi(3.141592);
	extern const double gravity(9.8);
}
```
헤더 파일에만 위에 처럼 해두고 include 해서 쓰면<br>이곳 저곳에서 상수 불러 올 때마다 메모리가 다름. <br>\[**각 translation unit(소스 파일)마다 독립된 변수가 정의되어 메모리가 낭비되거나, 중복 정의 오류(ODR 위반)가 발생할 수 있다\]<br>여기서 한 것은 선언이 아니라 정의.**<br>
```cpp
// Myconstants.h
#pragma once

namespace Constants
{
	extern const double pi;
	extern const double gravity;
}
```
```cpp
// Myconstant.cpp
namespace Constants
{
	extern const double pi(3.141592);
	extern const double gravity(9.8);
}

```
→ 이렇게 해결 가능.<br>**헤더는 선언만, cpp에 정의를 작성.**
이건 옛날 방식 해결법이고 c++17 이후부터는
```cpp
// Myconstants.h
#pragma once

namespace Constants
{
    inline constexpr double pi = 3.141592;
    inline constexpr double gravity = 9.8;
}
```
이렇게 해결한다고 함.
## 💻 코드 스니펫
```cpp
namespace work1
{
    namespace work11
    {
        namespace work111
        {
            int a = 2;
        }
    }
    int a = 1;
    void doSomething()
    {
        a += 3;
    }
}
// nested namespace c++14 부터는 이렇게도 됨
namespace work3::work33::work333
{
    int a = 2;
}

```
## 🔥 헷갈린 것들 / 질문
-
## ✅ 복습 체크
- [ ] 강의 완주
- [ ] 코드 직접 따라 침
- [ ] 복습 1회
