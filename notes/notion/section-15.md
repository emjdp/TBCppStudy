---
강의 수: 6
상태: 완료
섹션 번호: 15
섹션명: 섹션 15. 예외 처리
완료일:
  end: null
  start: 2026-08-19
  time_zone: null
완료한 강의 수: 6
중요도: ⭐ 중요
진도율: 100
총 시간: 1시간 8분
---

# 섹션 15. 예외 처리

## 📝 핵심 개념 정리
### 예외처리의 기본
```cpp
  try
  {
      if (x < 0.0) throw std::string("Negative input");

      cout << std::sqrt(x) << endl;
  }
  catch (std::string error_message)
  {
      cout << error_message << endl;
  }
```
throw를 받아줄 catch가 없으면 런타임 에러 발생
### 예외 처리와 스택 되감기
```cpp
#include <iostream>
using namespace std;

void last()
{
    cout << "last " << endl;
    cout << "Throws exception" << endl;

    throw -1;

    cout << "End last " << endl;
}

void third()
{
    cout << "Third" << endl;

    last();

    cout << "End third" << endl;
}

void second()
{
    cout << "Second" << endl;

    try
    {
        third();
    }
    catch (double)
    {
        cerr << "Second caught double exception" << endl;
    }

    cout << "End second " << endl;
}

void first()
{
    cout << "first" << endl;

    try
    {
        second();
    }
    catch (int)
    {
        cerr << "first caught int exception" << endl;
    }

    cout << "End first " << endl;
}
int main()
{
    cout << "Start" << endl;

    try
    {
        first();
    }
    catch (int)
    {
        cerr << "main caught int exception" << endl;
    }

    //uncaught exceptions
    catch (...)
    {
        cerr << "main caught ellipses exception" << endl;
    }


    cout << "End main" << endl;

    return 0;
}
```
### 예외 클래스와 상속
```cpp
class Exception
{
public:
    void report()
    {
        cerr << "Exception report" << endl;
    }
};

class ArrayException : public Exception
{
public:
    void report()
    {
        cerr << "Array exception" << endl;
    }
};
```
이후 예외 클래스를 throw
```cpp
 try
 {
     doSomething();
 }
 catch (ArrayException& e)
 {
     cout << "main()" << endl;
     e.report();
 }
 catch (Exception& e)
 {
     cout << "main()" << endl;
     e.report();
 }



 // ...

     catch (ArrayException& e)
    {
        cout << "doSomething()" << endl;
        e.report();
        throw e;
    }

        catch (Exception& e)
    {
        cout << "doSomething()" << endl;
        e.report();
    }
```
### std::exception
표준 예외 클래스(예: std::exception) 객체가 담고 있는 예외 메시지 문자열(const char\*)을 얻기 위해 호출하는 멤버 함수 : **what()**
```cpp
class CustomException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Custom exception";
    }
};
```
### 함수 try - 생성자에서 캐치 하기 위해 사용
```cpp
    B(int x) try : A(x)
    {
        //do initialization
    }
    catch (...)
    {
        cout << "Catch in B contructor" << endl;
        //throw; //자동으로 던져짐
    }
```
### 예외처리 주의점
```cpp
#include <iostream>
#include <memory>
using namespace std;

/*class A
{
public:
    ~A()
    {
        throw "error"; // 소멸자에서는 예외를 만들 수 없음
    }
};*/

int main()
{
    try
    {
        int* i = new int[1000000];
        //unique_ptr<int> up_i(i); // 스마트 포인터로 메모리 누수 방지 가능

        //do something with i
        throw "error";

        delete[] i;

        //A a;
    }

    catch (...)
    {
        cout << "Catch" << endl;
    }

    return 0;
}
```
스택 되감기 중 다른 예외가 처리되지 않거나 비정상 종료 될 수 있으므로 소멸자에서 throw를 하지 않음
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
