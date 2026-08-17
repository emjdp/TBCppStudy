---
강의 수: 9
상태: 완료
섹션 번호: 12
섹션명: 섹션 12. 상속
완료일:
  end: null
  start: 2026-08-17
  time_zone: null
완료한 강의 수: 9
중요도: ⭐⭐ OOP 핵심
진도율: 100
총 시간: 1시간 52분
---

# 섹션 12. 상속

## 📝 핵심 개념 정리
### 유도된 클래스들의 생성 순서
```cpp
#include <iostream>

using namespace std;

class Mother
{
public:
//private:
    int m_i;

public:
    Mother()
        : m_i(1)
    {
        cout << "Mother construction" << endl;
    }
};

class Child : public Mother
{
private:
    double m_d;

public:
    Child()
        :m_d(1.0)
    {
        cout << "Child construction" << endl;
    }
};

int main()
{
    Child c1;

    return 0;
}
```
Mother 생성자 후 Child 생성자.
public:<br>    Child()<br>        :m_d(1.0), Mother랑 다를게 없음. <br>Mother(1024) 이거 하려면<br>Mother(const int & i_in = 0)
	: m_i(i_in)<br>\{\}
### 상속과 접근 지정자
```cpp
class Base
{
public:
    int m_public;
protected:
    int m_protected;
private:
    int m_private;
};

class Derived : public Base
{
public:
    Derived()
    {
        m_protected = 123;
    }
};

class Derived2 : protected Base
{
public:
    Derived2()
    {
        Base::m_protected;
    }
};

class Derived3 : private Base
{
public:
    Derived3()
    {
        Base::m_protected;
    }
};

class GrandChild : public Derived3
{
public:
    GrandChild()
    {
        //Derived3::m_public; // 불가능
    }
};
```
### 상속받은 함수 오버라이딩
```cpp
class Base
{
protected:
    int m_i;

public:
    Base(int value)
        : m_i(value)
    { }

    void print()
    {
        cout << "I'm base " << endl;
    }

    friend std::ostream& operator << (std::ostream& out, const Base& b)
    {
        out << "This is base output" << endl;
        return out;
    }
};

class Derived : public Base
{
private:
    double m_d;

public:
    Derived(int value)
        : Base(value)
    { }

    void print() // 오버라이딩
    {
        cout << "I'm derived " << endl;
    }

    friend std::ostream& operator << (std::ostream& out, const Derived& b) // output 오퍼레이터 오버라이드
    {
        cout << static_cast<Base>(b); // Base으로 형변환 해서 This is base output 출력됨
        out << "This is derived output" << endl;
        return out;
    }
};
```
### 상속 받은 함수 감추기
```cpp
class Base
{
protected:
    int m_i;

public:
    Base(int value)
        : m_i(value)
    { }

    void print()
    {
        cout << "I'm base " << endl;
    }
};

class Derived : public Base
{
private:
    double m_d;

public:
    Derived(int value)
        : Base(value)
    { }

    using Base::m_i;

private:
    //void print() = delete; //방법1.
    using Base::print; // 방법2. 밖에서 부모클래스는 접근 안되는데 자식 클래스로는 가능
};
```
### 다중상속
```cpp
class USBDevice
{
private:
    long m_id;

public:
    USBDevice(long id) : m_id(id) {}
    long getID() { return m_id; }
    void plugAndPlay() {}
};

class NetworkDevice
{
public:
    long m_id;
    long getID() { return m_id; }
    void networking() {}
};

class USBNetworkDevice : public USBDevice, public NetworkDevice
{
public:
    USBNetworkDevice(long usb_id, long net_id)
        : USBDevice(usb_id), NetworkDevice(net_id)
    { }
};
```
```plain text
   A
  / \
B1   B2
  \ /
   C
```
다이아몬드 상속 주의
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
