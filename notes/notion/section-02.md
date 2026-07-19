---
강의 수: 14
상태: 완료
섹션 번호: 2
섹션명: 섹션 2. C++의 기본적인 사용법
완료일:
  end: null
  start: 2026-07-19
  time_zone: null
완료한 강의 수: 14
중요도: 기본
진도율: 100
총 시간: 3시간 27분
---

# 섹션 2. C++의 기본적인 사용법

## 📝 핵심 개념 정리
```cpp
#include <iostream>

int main()
{
	int x;
	std::cout << x << std::endl;
	return 0;
}
error C4700: uninitialized local variable 'x' used
```
<br><br>`int y = (x > 0) ? 1 : 2; // 삼항 연산자, x가 0보다 크면(참이면) 왼쪽거 실행 y = 1`
삼항 연산자의 존재에 대해서 알게됨.
선언과 정의, 헤더파일, 헤더가드의 필요성, 네임스페이스, 전처리기 기초.<br><br><br>`#pragma once` 로 중복 되는 것을 방지.
## 💻 코드 스니펫
```cpp
#include <iostream> //preprocessor directive

int main(void)
{
	1 + 3; // 표현식(expression)
	int x = 2; // 리터럴, literal
	x = 5;
	int y = x + 3;

	std::cout << x << std::endl; // 명령문(statement)
	std::cout << y;

	return 0;
}
```
```cpp
#include <iostream>

int main()
{
	int x = 5; // initialization // int x(5); 이것도 됨
	x = 123; //assignment x가 엘벨류 123이 얼벨류
	// x = x + 2 여기서 오른쪽에 있는 x는 변수가 아니라 값이 임시로 복사되는 거

	std::cout << x << std::endl;
	std::cout << &x << std::endl;

	std::cout << "여기부터 실습" << std::endl;

	int y = x;
	std::cout << y << std::endl;
	std::cout << x + y << std::endl; // (x+y)는 l-value 인가 아님 r-value 인가
	// 임시적인 값이므로 r-value


	return 0;
}
```
```cpp
#include <iostream> // cout, cin, emdl, ...
#include <cstdio>

int main()
{
    int x = 1024;
    double pi = 3.141592;
    //std::cout << "I love this lecture!" << std::endl;
    std::cout << "I love this lecture!\n\n\n\n\n"; // << std::endl; \n은 new line
    std::cout << "x is " << x << "pi is " << pi << std::endl;

    std::cout << "abc" << "\t" << "def" << std::endl;
    std::cout << "ab" << "\t" << "cdef" << std::endl;

    using namespace std;
    int z = 32;
    cout << z << endl;
    cout << "abc" << "\t" << "def" << endl;
    cout << "ab" << "\t" << "cdef" << endl;
    cout << "\a"; // 오디오 출력

    int s = 1;

    cout << "Before s was " << s << endl;
    cin >> s;
    cout << "Your input is " << s << endl;

    return 0;
}

```
```cpp
#include <iostream>

using namespace std;

void printHelloWorld()
{
    cout << "Hello World" << endl;
    return;
    cout << "Hello World2" << endl; // 출력안됨
}

int multiplyTwoNumbers(int num_a, int num_b)
{
    int sum = num_a + num_b;

    return sum;
}

int main()
{
    printHelloWorld();
    cout << 1 + 2 << endl;
    cout << multiplyTwoNumbers(8,13) << endl;
    cout << multiplyTwoNumbers(5, 64) << endl;


    return 0;
}

```
```cpp
#include <iostream>

namespace MySpace1
{
    namespace InnerSpace
    {
        int my_function()
        {
            return 0;
        }
    }
    int doSomething(int a, int b)
    {
        return a + b;
    }
}

namespace Myspace2
{
    int doSomething(int a, int b)
    {
        return a * b;
    }
}

using namespace std;

int main()
{
    using namespace MySpace1;
    doSomething(3, 4);
    MySpace1::InnerSpace::my_function();
    InnerSpace::my_function(); // using namespace MySpace1; 이거 해줘서 가능. 바로 my_function() 하려면 다음이 필요
    // using namespace MySpace1::InnerSpace;
   /*
    cout << MySpace1::doSomething(3, 4) << endl;
    cout << MySpace2::doSomething(3, 4) << endl;
   */
}

```
Chapter2_10.cpp에 정의된 `#define LIKE_APPLE`은 해당 파일 안에서만 유효.<br>독립적으로 컴파일되는 different_source.cpp는 이 매크로의 존재를 알지 못하므로, `different_source.cpp` 내부의 `#ifdef LIKE_APPLE` 조건문은 거짓이 되어 `"Orange"`가 출력
## 🔥 헷갈린 것들 / 질문
- `std::cout << &x << std::endl;`  내거가 강사보다 긴 이유는 나는 x64 강사는 x86으로 빌드 해서? <br>→ yes
- chapter2_10.cpp 에서 different_source.cpp를 include 안했는데 왜 작동하는거지?<br>→ 컴파일이 완료된 후, 링커가 각각 컴파일되어 생성된 오브젝트 파일들을 하나로 묶었기 때문.
## ✅ 복습 체크
- [x] 강의 완주
- [x] 코드 직접 따라 침
- [x] 복습 1회
