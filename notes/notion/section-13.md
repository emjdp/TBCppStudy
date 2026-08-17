---
강의 수: 11
상태: 진행 중
섹션 번호: 13
섹션명: 섹션 13. 가상 함수들
완료일: null
완료한 강의 수: 4
중요도: ⭐⭐ OOP 핵심
진도율: 36
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
- [ ] 복습 2회 (OOP 핵심 섹션은 2회 복습)
