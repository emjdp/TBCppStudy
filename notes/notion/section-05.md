---
강의 수: 10
상태: 완료
섹션 번호: 5
섹션명: 섹션 5. 변수 범위와 더 다양한 변수들
완료일:
  end: null
  start: 2026-07-26
  time_zone: null
완료한 강의 수: 10
중요도: ⭐ 중요
진도율: 100
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
```cpp
#include <iostream>

auto add(int x, int y)
{
    return x + y;
}

//auto add(double x, double y)
//{
//    return x + y;
//}

// template 으로 아무거나 받아오는 걸 만들 수 있음.

int main()
{
    using namespace std;

    auto a = 123;
    auto d = 123.0;
    auto c = 1 + 2.0;
    auto result = add(1, 2);

    return 0;
}
```
```cpp
#include <iostream>
#include <typeinfo>

enum Color // Enumeration 열거
{
    COLOR_BLACK = -2,
    COLOR_RED,
    COLOR_BLUE,
    COLOR_GREEN,
    COLOR_SKYBLUE,
    //BLUE는 겹쳐서 안됨.
};

enum Feeling
{
    HAPPY,
    JOY,
    TIRED,
    BLUE
};

int main()
{
    using namespace std;

    Color my_color = COLOR_BLACK;
    cout << my_color << " " << COLOR_BLACK << endl;
    Color paint = COLOR_BLACK;
    Color house(COLOR_BLUE);
    Color appe{ COLOR_RED };

    int color_id = COLOR_GREEN;
    cout << color_id << endl;

    int in_number;
    cin >> in_number;

    if (in_number == static_cast<Color>(0)) // 열거형은 정수와 비교될 때 자동으로 정수형으로 암시적 형변환 되므로, 사실상 in_number == 0 과 똑같다.
        my_color = static_cast<Color>(0);



```
```cpp
    enum class Color1
    {
        BLACK,
        RED,
        BLUE,
    };

    enum class Fruit1
    {
        BANANA,
        APPLE,
    };

    Color1 color1 = Color1::RED;
    Fruit1 fruit1 = Fruit1::APPLE; // namespace로 묶어주는거랑 비슷한듯

    // if (color1 == fruit1) // 불가능
    if (static_cast<int>(color1) == static_cast<int>(fruit1)) // 테스트용. 실제로 쓸일은 없음.
        cout << "Color is fruit ? " << endl;
```
## 🔥 헷갈린 것들 / 질문
-
```plain text
struct Employee // 2 + 4 + 8 = 14
{
    short   id; // 2 byte
    int     age; // 4 byte
    double  wage; // 8 byte
};
```
```plain text
    Employee emp1;
    cout << sizeof(Employee) << endl;
```
했더니 14가 나옴. ?!?!
**cpu는 데이터를 1 byte 단위로 읽는게 아니라 4 byte나 8 byte 난위로 묶어서 읽음. 만약에 패딩(빈공간 끼워 넣기) 없이 4byte int 변수가 4배수 아닌 곳에 걸쳐 있다면  CPU는 2번 접근 해서 데이터를 가져와 조합해야 함.**
**공간의 효율보다 시간의 효율을 우선 시 해서 이런짓을 하나봄 **
## ✅ 복습 체크
- [x] 강의 완주
- [x] 코드 직접 따라 침
- [x] 복습 1회
