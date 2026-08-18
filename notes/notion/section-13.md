---
강의 수: 11
상태: 완료
섹션 번호: 13
섹션명: 섹션 13. 가상 함수들
완료일:
  end: null
  start: 2026-08-18
  time_zone: null
완료한 강의 수: 11
중요도: ⭐⭐ OOP 핵심
진도율: 100
총 시간: 1시간 29분
---

# 섹션 13. 가상 함수들

## 📝 핵심 개념 정리
다형성의 핵심. virtual, override, 순수 가상 함수, 추상 클래스, 가상 소멸자 정리
```cpp
class Animal
{
protected:
    string m_name;

public:
    Animal(std::string name)
        : m_name(name)
    { }

public:
    string getName() { return m_name; }

    virtual void speak() const
    {
        cout << m_name << " ??? " << endl;
    }
};
```
```cpp
    Cat cats[] = { Cat("cat1"),Cat("cat2") ,Cat("cat3") ,Cat("cat4") ,Cat("cat5") };
    Dog dogs[] = { Dog("dog1"),Dog("dog2") };

    Animal* my_animals[] = { &cats[0], &cats[1],&cats[2] ,&cats[3] ,&cats[4],
                            &dogs[0], &dogs[1] };

    for (int i = 0; i < 7; ++i) // for문 2개 쓸거 포인터로 하나로 줄임
        my_animals[i]->speak();
```
<span underline="true">***virtual***</span>  로 포인터로 받아와서 실행해도 각각의 원래 함수 기능을 수행.
```cpp
    B& ref = c; // B는 virtual이 아니어도 A를 상속받았기 때문에
    ref.print(); // c가 나옴
```
```cpp
class A
{
public:
    virtual void print() { cout << "A" << endl; }
};

class B : public A
{
public:
    void print() override final { cout << "B" << endl; } // override 키워드는 실수 방지용
    //virtual void print() { cout << " B " << endl; }
};

class C : public B
{
public:
    //virtual void print() { cout << " C " << endl; } // fianl 키워드로 오버라이드 불가
};
```
```cpp
class A1
{
public:
    void print() { cout << "A1" << endl; }
    virtual A1* getThis()
    {
        cout << "A::getThis()" << endl;
        return this;
    }
};

class B1 : public A1
{
public:
    void print() { cout << "B1" << endl; }
    virtual B1* getThis()
    {
        cout << "B::getThis()" << endl;
        return this;
    }
};

int main()
{
    A1 a1;
    B1 b1;
    A1 &ref1 = b1;
    b1.getThis()->print();
    ref1.getThis()->print(); // print는 가상함수가 아니므로 a1이 출력됨
```
```cpp
int main()
{
    Derived* derived = new Derived(5);
    Base* base = derived;
    delete base; // 소멸자도 virtual이어야 derived도 지워지면서 메모리 누수 안됨
```
### 정적 바인딩
```cpp
int result;
switch (op)
{
case 0: result = add(x, y); break;
case 1: result = subtract(x, y); break;
case 2: result = multiply(x, y); break;
}

cout << result << endl;
```
### 동적 바인딩
```cpp
    int(*func_ptr)(int, int) = nullptr;
    switch (op)
    {
    case 0: func_ptr = add; break;
    case 1: func_ptr = subtract; break;
    case 2: func_ptr = multiply; break;
    }

    cout << func_ptr(x, y) << endl;
```
`virtual`로 선언된 함수는 동적 바인딩의 대상이 됨.
```cpp
class Parent
{
public:
    virtual void first()  {}
    virtual void second() {}
};

class Child : public Parent
{
public:
    void first() override {}
};

Child child;
Parent& reference = child;

reference.first();   // Child::first()
reference.second();  // Parent::second()
```
```plain text
Parent 객체
  └─ vptr ──> Parent용 vtable
                 ├─ Parent::first()
                 └─ Parent::second()

Child 객체
  └─ vptr ──> Child용 vtable
                 ├─ Child::first()    ← 재정의됨
                 └─ Parent::second()  ← 재정의되지 않음
```
- 가상 함수가 있는 객체에는 일반적으로 숨겨진 `vptr` 포함됨
- `vptr`은 그 객체의 실제 타입에 대응하는 `vtable`을 가리킴
- `Child`가 재정의한 `first()`의 슬롯은 `Child::first()`를 가리킴
- 재정의하지 않은 `second()`의 슬롯은 계속 `Parent::second()`를 가리킴
- 호출 시 `vptr`과 `vtable`을 통해 실제 실행할 함수가 결정되므로 동적 바인딩이 가능
### 순수 가상 함수
` virtual void speak() const = 0; // pure virtual function` <br>= 0 은 순수 가상 함수로 지정한다는 문법
### 추상 기본 클래스 - 순수 가상 함수를 하나 이상 포함한 클래스
### 인터페이스 클래스 - 객체가 제공해야 할 기능의 형식만 정의하는 클래스
```cpp
class IErrorLog // <- 인터페이스 클래스 (기능 없음
{
public:
    virtual bool reportError(const char* errorMessage) = 0;
    virtual ~IErrorLog() {}
};

class FileErrorLog : public IErrorLog
{
public:
    bool reportError(const char* errorMessage) override
    {
        cout << "Writing error to a file " << endl;
        return true;
    }
};

class ConsoleErrorLog : public IErrorLog
{
public:
    bool reportError(const char* errorMessage) override
    {
        cout << "Priting error to a console " << endl;
        return true;
    }
};

void doSomething(IErrorLog& log)
{
    log.reportError("Runtime error!!");
}
```
`doSomething()` 은 전달 받은 객체가 파일 기록기인지 콘솔 기록기인지 알 필요 없음
```cpp
FileErrorLog fileLog;
ConsoleErrorLog consoleLog;

doSomething(fileLog);     // FileErrorLog::reportError()
doSomething(consoleLog);  // ConsoleErrorLog::reportError()
```
`doSomething()`  수정없이 기능 추가 가능
```plain text
순수 가상 함수
    ↓ 하나 이상 포함
추상 기본 클래스
    ↓ 구현보다 규약 제공에 집중
인터페이스 클래스
```
### 객체 잘림
부모 클래스에 없는 자식 클래스 내용을 부모 클래스에 넣으려고 할때 발생 → 다형성 사용 불가
```cpp
    Derived d;
    Base& b = d;
// &을 빼먹으면 밑에 처럼 됨
    Base b;
    b = d; // 객체 잘림. 다형성 사용 불가
```
### reference wrapper
```cpp
    std::vector<Base*> my_vec;
    my_vec.push_back(&a);
    my_vec.push_back(&c);

    for (auto& ele : my_vec)
        ele->print();

    // 레퍼런스로 구현하고 싶으면

    std::vector<std::reference_wrapper<Base>> my_vec2;
    my_vec2.push_back(e);
    my_vec2.push_back(f);

    for (auto& ele : my_vec2)
        ele.get().print();
```
### 동적 형변환
```cpp
    Derived1 d1;
    d1.m_j = 2048;

    Base* base = &d1;
    // base.m_j 접근불가

    auto* base_to_d1 = dynamic_cast<Derived1*>(base); // 동적 형변환
    cout << base_to_d1->m_j << endl; // 접근 가능
```
캐스팅 실패하면 nullptr 넣음
### 유도된 클래스에서 출력 연산자 사용하기
```cpp
class Base
{
public:
    Base() {}

    friend std::ostream& operator << (std::ostream& out, const Base& b)
    {
        return b.print(out);
    }

    virtual std::ostream& print(std::ostream& out) const
    {
        out << "Base";
        return out;
    }
};

class Derived : public Base
{
public:
    Derived() {}

    virtual std::ostream& print(std::ostream& out) const override
    {
        out << "Derived";
        return out;
    }
};
```
`operator<<` 는 비멤버 함수여서 가상 함수로 만들거나 오버라이딩 불가능
그래서 가상 멤버 함수 `print()` 를 호출하게 하고 유도 클래스에서 오버라이딩 해서 다형적 출력을 구현.
## 💻 코드 스니펫
```cpp
// 직접 따라 친 코드 중 기억할 것
```
## 🔥 헷갈린 것들 / 질문
-
## ✅ 복습 체크
- [x] 강의 완주
- [x] 코드 직접 따라 침
- [x] 복습 1회
- [ ] 복습 2회 (OOP 핵심 섹션은 2회 복습)
