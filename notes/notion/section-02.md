---
강의 수: 14
상태: 진행 중
섹션 번호: 2
섹션명: 섹션 2. C++의 기본적인 사용법
완료일: null
완료한 강의 수: 0
중요도: 기본
진도율: 0
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
## 🔥 헷갈린 것들 / 질문
- `std::cout << &x << std::endl;`  내거가 강사보다 긴 이유는 나는 x64 강사는 x86으로 빌드 해서?
## ✅ 복습 체크
- [ ] 강의 완주
- [ ] 코드 직접 따라 침
- [ ] 복습 1회
