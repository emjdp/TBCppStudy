---
강의 수: 7
상태: 완료
섹션 번호: 16
섹션명: 섹션 16. 의미론적 이동과 스마트 포인터
완료일:
  end: null
  start: 2026-08-19
  time_zone: null
완료한 강의 수: 7
중요도: ⭐ 중요
진도율: 100
총 시간: 1시간 45분
---

# 섹션 16. 의미론적 이동과 스마트 포인터

## 📝 핵심 개념 정리
move semantics, unique_ptr / shared_ptr / weak_ptr 차이 정리
```cpp
// RAII : Resource Acquisition Is Initiallization
void doSomething()
{
    Resource* res = new Resource; // dull pointer

    // work with res
    if (true)
    {
        return; // early return // try-catch 라면 throw 하면서 delete 불가
    }

    delete res; // 실행안됨

    return;
}
```
스마트 포인터로 구현
```cpp
#pragma once

#include <iostream>

template<class T>
class AutoPtr
{
public:
	T* m_ptr = nullptr;

public:
	AutoPtr(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}

	~AutoPtr()
	{
		if (m_ptr != nullptr) delete m_ptr;
	}

	// move semantics

	AutoPtr(AutoPtr& a)
	{
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;
	}

	AutoPtr& operator = (AutoPtr& a)
	{
		if (&a == this)
			return *this;

		delete m_ptr;
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;
		return *this;
	}


	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr = nullptr; }
};
```
```cpp
void doSomething2()
{
    try
    {
        AutoPtr<Resource> res(new Resource); // smart pointer

        if (false)
        {
            throw - 1;
        }
    }
    catch (...)
    {

    }
}
```
    // syntax vs semantics<br>    // value semantics (copy semantics)<br>    // reference semantics (pointer)<br>    // move semantics (move)
### R-reference
```cpp
    void doSomething(int& lref)
{
    cout << "L-value ref" << endl;
}

void doSomething(int&& lref)
{
    cout << "R-value ref" << endl;
}

    //...

    int x = 5;
    int y = getResult();
    const int cx = 6;
    const int cy = getResult();

    // L-value references

    int& lr1 = x;           // Modifiable l-values
    //int &lr2 = cx;        // Non-modiable l-values
    //int &lr3 = 5;         // R-values

    const int& lr4 = x;     // Modifiable l-values
    const int& lr5 = cx;    // Non-modifiable l-values
    const int& lr6 = 5;     // R-values

    // R-value references

    //int &&rr1 = x;        // Modifiable l-values
    //int &&rr2 =cx;        // Non-modiable l-values
    int&& rr3 = 5;          // R-values
    int&& rrr = getResult();

    //const int &&rr4 = x;  // Modifiable l-values
    //const int &&rr5 = cx; // Non-Modifiable l-values
    const int &&rr6 = 5;    // R-values
```
### 이동 생성자와 이동 대입 연산자 (Move Semantics)
#### 1. 이동(Move)이 왜 필요한가?
- **깊은 복사(Deep Copy)**: 임시 객체(R-value)를 대입할 때도 새 메모리를 할당해 1000만 개 데이터를 일일이 복사함 → 극심한 낭비
- **이동(Move)**: 어차피 버려질 임시 객체라면 새 메모리를 파지 않고 **포인터 주소만 가로채기(Shallow Copy)** → 복사 비용 0
#### 2. 이동 생성자/대입 구현의 핵심 2단계
1. **자원 가로채기**: `m_ptr = a.m_ptr;` (얕은 복사)
2. **원래 주인 무력화**: `a.m_ptr = nullptr;` (이걸 안 하면 임시 객체 소멸자가 메모리를 날려버려 Double Free 에러 발생)
#### 3. 복사와 이동의 오버로딩 선택 기준
- `AutoPtr(const AutoPtr& a)` : **L-value**(이름 있는 변수)가 들어올 때 호출 → 안전하게 깊은 복사
- `AutoPtr(AutoPtr&& a)` : **R-value**(임시 객체/우측값)가 들어올 때 호출 → 소유권 이전(이동)
### **std::move → R-value로 리턴**
```cpp
    vector<string> v;
    string str = "Hello";

    v.push_back(str); // L-value 로

    cout << str << endl; // Hello
    cout << v[0] << endl; // Hello

    v.push_back(std::move(str)); // R-value 로

    cout << str << endl; // 출력 없음
    cout << v[0] << " " << v[1] << endl; // Hello Hello 이동해옴
```
### std::**unique_ptr**
- RAII 패턴: 객체가 스코프를 벗어나면 자동으로 메모리를 해제하여 메모리 누수를 방지.
- 단독 소유권: 특정 힙 메모리 주소의 주인은 ** **하나만 존재해야 함.
#### 생성 및 대입
- 복사 불가: 소유권이 둘이 될 수 없으므로 복사 생성자/복사 대입 연산자가 삭제되어 있음.
- 이동 가능: std::move를 통해 소유권을 완전히 이전할 수 있음. (이전된 기존 포인터는 nullptr가 됨)
- 생성 권장: std::make_unique\<T\>(인자) 사용
```cpp
auto p1 = std::make_unique<Resource>(5);
// auto p2 = p1;            // [X] 컴파일 에러 (복사 불가)
auto p2 = std::move(p1);    // [O] 소유권 이전 (이제 p1은 nullptr)
```
#### 함수와의 사용 패턴
소유권 이전 : void foo(std::unique_ptr\<T\> p)
- 호출 시 foo(std::move(p1)) 형태로 소유권을 넘김. (함수 종료 시 메모리 해제)
단순 사용/수정 : void foo(T\* p) 또는 void foo(T& p)
- 소유권은 호출자가 유지하고 함수는 알맹이만 사용.
- 호출 시 foo(p1.get()) 또는 foo(\*p1) 형태로 전달.
함수 반환 :
- std::unique_ptr\<T\>를 값으로 반환할 때는 return std::move(p); 하지 말고 그냥 return p; 할 것 (RVO 최적화 적용).
하면 안 되는 것
- 하나의 raw 포인터를 여러 unique_ptr에 바인딩 금지 → 이중 해제 크래시
- unique_ptr가 관리하는 주소를 수동으로 delete 금지
### **std::shared_ptr**
#### 핵심 개념
- 공동 소유권 : 하나의 자원을 여러 스마트 포인터가 동시에 공유하고 소유할 수 있음.
- 참조 카운팅 : 자원을 가리키는 shared_ptr의 개수를 추적하여, 카운트가 0이 되는 순간(마지막 소유자가 소멸할 때) 자동으로 자원을 해제함.
#### 생성 및 복사
- 복사 가능 : 복사 생성/복사 대입이 가능하며, 복사될 때마다 참조 카운트가 1씩 증가함.
- 생성 권장: std::make_shared 사용
#### 하면 안 되는 것
- 동일한 raw 포인터로 여러 개의 shared_ptr를 개별 생성 금지
	- 이유: 서로 컨트롤 블록을 공유하지 못해 각자 카운트 1을 가지고 독립 동작함.
	- 결과: 먼저 소멸하는 포인터가 자원을 삭제하여 남은 포인터가 댕글링 포인터가 되고, 최종적으로 이중 해제(Double Free) 런타임 크래시 발생.
	- 올바른 방법: 반드시 make_shared로 생성하거나, 기존 shared_ptr를 복사(ptr2 = ptr1)하여 사용할 것.
### std::weak_ptr
1. 사용 이유
	- shared_ptr끼리 서로 참조하면 참조 횟수가 0이 되지 않아 객체가 소멸하지 않을 수 있다.
	- 소유권이 필요 없는 쪽을 weak_ptr로 바꾸면 순환 참조를 방지할 수 있다.
2. 특징
	- 객체를 소유하지 않고 관찰만 한다.
	- shared_ptr의 참조 횟수를 증가시키지 않는다.
	- -\>와 \*로 객체에 직접 접근할 수 없다.
3. 객체 접근
	- lock()으로 임시 shared_ptr를 얻어 접근한다.
	- 객체가 살아 있으면 유효한 shared_ptr를 반환한다.
	- 객체가 이미 소멸했다면 빈 shared_ptr를 반환한다.
```cpp
class Person
{
private:
    std::string m_name;
    std::weak_ptr<Person> m_partner;

public:
    std::shared_ptr<Person> getPartner() const
    {
        return m_partner.lock();
    }
};
```
```cpp
auto partner = lucy->getPartner();

if (partner)
{
    std::cout << partner->getName() << '\n';
}
```
## 스마트 포인터 비교
- `unique_ptr`: 하나의 포인터만 객체를 소유하며 복사할 수 없다.
- `shared_ptr`: 여러 포인터가 객체를 공동으로 소유한다.
- `weak_ptr`: 객체를 소유하지 않고 관찰하며 순환 참조를 방지한다.
## 💻 코드 스니펫
```cpp
// 직접 따라 친 코드 중 기억할 것
```
## 🔥 헷갈린 것들 / 질문
-
## ✅ 복습 체크
- [ ] 강의 완주
- [ ] 코드 직접 따라 침
- [ ] 복습 1회
