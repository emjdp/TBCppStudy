---
강의 수: 15
상태: 완료
섹션 번호: 9
섹션명: 섹션 9. 객체지향의 기초
완료일:
  end: null
  start: 2026-08-10
  time_zone: null
완료한 강의 수: 15
중요도: ⭐⭐ OOP 핵심
진도율: 100
총 시간: 3시간 16분
---

# 섹션 9. 객체지향의 기초

## 📝 핵심 개념 정리
**다음 학기 수업의 심장부.** 클래스, 생성자/소멸자, 접근 지정자, this 포인터 등을 남에게 설명할 수 있을 정도로 정리
### 객체지향 프로그래밍과 클래스
```cpp
class Friend
{
public: // access specifier (public, private, protected)
    string name;
    string address;
    int age;
    double height;
    double weight;

    void print()
    {
        cout << name << " " << address << " " << age << " " << height << " " << weight << endl;
    }
};

int main()
{

    Friend jj("Jack Jack", "Uptown", 2,30, 10); // instanciation, instance
    /*
    print(jj.name, jj.address, jj.age, jj.height, jj.weight);
    print(jj);
    */

    jj.print();

    vector<Friend> my_friends;
    my_friends.resize(2);

    //my_friends[0].print();
    //my_friends[1].print();
    for (auto& ele : my_friends)
        ele.print();

    return 0;
}
```
## encapsulation 캡슐화
```cpp
class Date
{
    int m_month;
    int m_day;
    int m_year;
public:         //access specifier
    void setDate(const int& month_input, const int& day_input, const int& year_input)
    {
        m_month = month_input;
        m_day = day_input;
        m_year = year_input;
    }

    void setMonth(const int& month_input)
    {
        m_month = month_input;
    }

    const int getDay()
    {
        return m_day;
    }

    void copyFrom(const Date& original)
    {
        m_month = original.m_month;
        m_day = original.m_day;
        m_year = original.m_year;
    }
};
```
초기화
```cpp
#include <iostream>
using namespace std;

class B
{
private:
    int m_b;
public:
    B(const int& m_b_in)
        : m_b(m_b_in)
    { }
};
class Something
{
private:
    int     m_i = 100;
    double  m_d = 100.0;
    char    m_c = 'F';
    int m_arr[5] = { 100,200,300,400,500 };
    B m_b{ 1024 };
    // 이렇게 초기화 해둬도 생성자가 우선
public:
    Something()
        : m_i{ 1 }, m_d{ 3.14 }, m_c{ 'a' }, m_arr{ 1,2,3,4,5 }, m_b(m_i - 1)
    {
        m_i = 3;
        m_d = 3.0;
        m_c += 3;
    }

    void print()
    {
        cout << m_i << " " << m_d << " " << m_c << endl;
        for (auto& e : m_arr)
            cout << e << " ";
        cout << endl;
    }
};

int main()
{
    Something som;
    som.print();
    return 0;
}
```
## 위임 생성자
```cpp
#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int m_id;
    string m_name;
public:
    // 이름만 받으면 id를 0으로 지정해서 아래 생성자에게 위임
    Student(const string& name_in)
        : Student(0,name_in)
    {}

    // 실제 멤버 초기화를 담당하는 생성자
    Student(int id_in, const string& name_in)
        : m_id(id_in), m_name(name_in)
    {}

    void print()
    {
        cout << m_id << " " << m_name << endl;
    }
};

int main()
{
    Student st1(0, "Jack Jack");
    Student st2("John");

    st1.print();
    st2.print();

    return 0;
}
```
## 소멸자
```cpp
class Simple
{
private:
    int m_id;

public:
    Simple(const int & id_in)
        : m_id(id_in)
    {
        cout << "Constructor " << m_id << endl;
    }

    ~Simple()
    {
        cout << "Destructor " << m_id << endl;
    }
};
```
```cpp
class InArray
{
private:
    int* m_arr = nullptr;
    int m_lenght = 0;

public:
    InArray(const int lenght_in)
    {
        m_lenght = lenght_in;
        m_arr = new int{ m_lenght };

        cout << "Constructor " << endl;
    }

    ~InArray()
    {
        if(m_arr != nullptr)
            delete[] m_arr;
    }

    int size() { return m_lenght; }

};
```
## this 포인터와 연쇄 호출

```cpp
class Simple
{
private:
    int m_id;

public:
    Simple(int id)
    {
        setID(id); // this -> setID(id) 가 숨어 있음

        cout << this << endl; // 자기 주소를 출력
    }

    void setID(int id) { m_id = id; }

    int getID() { return m_id; }
};
```
### 연쇄호출
```cpp
class Calc
{
private:
    int m_value;

public:
    Calc(int init_value)
        : m_value(init_value)
    { }

    Calc& add(int value) { m_value += value; return *this; }
    Calc& sub(int value) { m_value -= value; return *this; }
    Calc& mult(int value) { m_value *= value; return *this; }

    void print()
    {
        cout << m_value << endl;
    }
};
```
```cpp
    Calc cal(10);
    cal.add(10).sub(1).mult(2).print();
```
풀어서 쓰면
```cpp
Calc cal(10);
Calc &temp1 = cal.add(10);
Calc &temp2 = temp1.sub(1);
Calc &temp3 = temp2.mult(2);
temp3.print();
```
## 클래스 코드와 헤더 파일
#### Calc.h
```cpp
#pragma once

#include <iostream>

class Calc
{
private:
    int m_value;

public:
    Calc(int init_value);

    Calc& add(int value);
    Calc& sub(int value);
    Calc& mult(int value);

    void print();
};
```
### Calc.cpp
```cpp
#include "Calc.h"

Calc::Calc(int init_value)
    : m_value(init_value)
{
}

Calc& Calc::add(int value) { m_value += value; return *this; }
Calc& Calc::sub(int value) { m_value -= value; return *this; }
Calc& Calc::mult(int value) { m_value *= value; return *this; }

void Calc::print()
{
    std::cout << m_value << std::endl;
}
```
### Chapter9_8.cpp
```cpp
#include "Calc.h"

int main()
{

    Calc cal(10);
    cal.add(10).sub(1).mult(2).print();

    return 0;
}
```
## 클래스와 const
```cpp
class Something
{
public:
    int m_value = 0;

    Something(const Something& st_in)
    {
        m_value = st_in.m_value;

        cout << "Copy constructor" << endl;
    }

    Something()
    {
        cout << "Constructor" << endl;
    }

    void setValue(int value) { m_value = value; }
    int getValue() const
    {
        return m_value;
    }
};

void print(Something st)
{
    cout << &st << endl;
    cout << st.getValue() << endl;
}

void cprint(const Something &st)
{
    cout << &st << endl;
    cout << st.getValue() << endl;
}
```
```cpp
int main()
{
    //const Something something;
    //something.setValue(3); // const라서 불가능
    //cout << something.getValue() << endl; // const 맴버 func이 아니라서 사용 불가

    Something some;

    cout << &some << endl;

    print(some);
    cprint(some); // const reference로 복사 안하고 사용
```
### const로 오버로딩
```cpp
class Myfun
{
public:
    string m_value = "default";

    const string& getValue() const
    {
        cout << "const version" << endl;
        return m_value;
    }

    string& getValue()
    {
        cout << "non-const version" << endl;
        return m_value;
    }
};
```
```cpp
    // 오버로딩 가능
    Myfun mf;
    mf.getValue() = 10;

    const Myfun mf2;
    mf2.getValue();
```
## 정적 멤버 변수

```cpp
int generateID()
{
    static int s_id = 0;
    return ++s_id;
}
```
```cpp
int main()
{
    cout << generateID() << endl; // 1
    cout << generateID() << endl; // 2
    cout << generateID() << endl; // 3
```
```cpp
class Something
{
public:
    static int s_value;
};

int Something::s_value = 1;
```
```cpp
cout << &Something::s_value << " " << Something::s_value << endl;
Something st1;
Something st2;
st1.s_value = 2;
cout << &st1.s_value << " " << st1.s_value << endl;
cout << &st2.s_value << " " << st2.s_value << endl;
Something::s_value = 1024;
cout << &Something::s_value << " " << Something::s_value << endl;
```
---
## 정적 멤버 핵심
- 일반 멤버 변수: 객체마다 따로 존재
- `static` 멤버 변수: 클래스 전체가 하나를 공유
- `static` 멤버 함수: 객체 없이 호출하며 `this`가 없음
- 함수 내부 `static` 변수: 함수가 끝나도 값을 기억함
```cpp
class Something
{
public:
    int m_value;          // 객체마다 따로
    static int s_value;   // 모든 객체가 공유

    static int getValue()
    {
        return s_value;
    }
};

int Something::s_value = 1; // 정적 멤버 변수 정의
```
```cpp
Something a, b;

a.m_value = 10;
b.m_value = 20;            // 서로 다른 값

Something::s_value = 30;   // a와 b가 함께 사용
Something::getValue();     // 객체 없이 호출
```
### 판단 기준
- 객체마다 달라야 한다 → 일반 멤버
- 모든 객체가 공유한다 → `static` 멤버
- 특정 객체가 필요 없는 기능이다 → `static` 함수
### 이런 문법도 있구나
```cpp
class Something
{
public:
    class _init
    {
    public:
        _init()
        {
            s_value = 9876;
        }
    };

private:
    static int s_value;
    int m_value;

public:
    static _init s_initializer;

    static int getValue()
    {
        return s_value; // this->s_value 사용 불가능
    }
```
```cpp
static int s_id = 0; // 함수가 끝나도 값 유지
```
```cpp
Something::_init Something::s_initializer;
```
- `_init` 자료형의 정적 객체 `s_initializer`를 실제로 만드는 문법
- 객체 생성자를 `main()` 전에 실행하는 예제
```cpp
int (Something::*fptr1)() = &Something::temp;
```
- 일반 멤버 함수 포인터
- 호출할 객체가 필요함
```cpp
int (*fptr2)() = &Something::getValue;
```
- 정적 멤버 함수 포인터
- 일반 함수 포인터처럼 사용 가능
## 친구 함수와 클래스
 클래스의 멤버 함수가 아니지만 private 멤버에 접근해야 할 때 사용
```cpp
#include <iostream>
using namespace std;

class A; // 전방선언 forward declaration

class B
{
private:
    int m_value = 2;

public:
    void doSomething(A& a);
};

class A
{
private:
    int m_value = 1;

    //friend class B;
    friend void B::doSomething(A& a);
};

void B::doSomething(A& a)
{
    cout << a.m_value << endl;
}

int main()
{
    A a;
    B b;
    b.doSomething(a);

    return 0;
}
```
## 임시 객체

```cpp
class Cents
{
private:
    int m_cents;

public:
    Cents(int cents) { m_cents = cents; }

    int getCents() const { return m_cents; }
};

Cents add(const Cents& c1, const Cents& c2)
{
    return Cents(c1.getCents() + c2.getCents());
}

int main()
{
    cout << add(Cents(6), Cents(8)).getCents();
    return 0;
}
```
Cents cents1(6); // 이름이 있는 객체<br>Cents(6);        // 이름이 없는 임시 객체
실행 흐름:
```plain text
Cents(6) + Cents(8)
        ↓
add()가 내부 값을 더함
        ↓
Cents(14)를 반환
        ↓
Cents(14).getCents()
        ↓
14 출력
```
## nested types
```cpp
class Fruit
{
public:
    enum FruitType
    {
        APPLE, BANANA, CHERRY,
    };

private:
    FruitType m_type;

public:
    Fruit(FruitType type) : m_type(type)
    { }

    FruitType getType() { return m_type; }
};
```
## 실행 시간 측정

```cpp
#include <iostream> // cout, endl
#include <chrono>   // chrono 관련 기능
#include <ratio>    // ratio<1>

class Timer
{
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<clock_t> start_time = clock_t::now();

public:
    void elapsed()
    {
        std::chrono::time_point<clock_t> end_time = clock_t::now();

        cout << std::chrono::duration_cast<second_t>(
            end_time - start_time)
            .count()
            << endl;
    }
};
```
## 💻 코드 스니펫
```cpp
// 직접 따라 친 코드 중 기억할 것
```
## 🔥 헷갈린 것들 / 질문
## static 멤버 함수 안에서 `this` 포인터를 사용할 수 없는 이유
### 정답: B
> `static` 멤버 함수는 특정 객체와 연결되지 않으므로 `this` 포인터가 전달되지 않는다.
### 핵심 개념
`this`는 **현재 멤버 함수를 호출한 객체의 주소를 가리키는 포인터**이다.
일반 멤버 함수는 객체를 통해 호출되므로 함수 내부에서 `this`를 사용할 수 있다.
```plain text
class Player
{
public:
    void PrintAddress()
    {
        std::cout << this << '\n';
    }
};

Player player;
player.PrintAddress();  // this는 &player를 가리킨다.
```
반면 `static` 멤버 함수는 특정 객체가 아닌 **클래스 자체에 속한 함수**이다. 객체를 생성하지 않아도 클래스 이름만으로 호출할 수 있다.
```plain text
class Player
{
public:
    static void Print()
    {
        // std::cout << this;  // 오류: static 함수에는 this가 없다.
    }
};

Player::Print();
```
`Player::Print()`를 호출할 때는 어떤 `Player` 객체도 지정하지 않았다. 따라서 `this`가 가리킬 대상도 존재하지 않는다.
### 일반 멤버 함수와 static 멤버 함수 비교
<table header-row="true">
<tr>
<td>구분</td>
<td>일반 멤버 함수</td>
<td>`static` 멤버 함수</td>
</tr>
<tr>
<td>특정 객체에 종속되는가?</td>
<td>예</td>
<td>아니요</td>
</tr>
<tr>
<td>`this` 포인터가 있는가?</td>
<td>예</td>
<td>아니요</td>
</tr>
<tr>
<td>객체 없이 호출 가능한가?</td>
<td>아니요</td>
<td>예</td>
</tr>
<tr>
<td>인스턴스 멤버에 직접 접근 가능한가?</td>
<td>예</td>
<td>아니요</td>
</tr>
<tr>
<td>`static` 멤버에 접근 가능한가?</td>
<td>예</td>
<td>예</td>
</tr>
</table>
### static 함수에서 인스턴스 멤버에 접근하려면?
`static` 함수도 객체를 명시적으로 전달받으면 해당 객체의 멤버에 접근할 수 있다.
```plain text
class Player
{
private:
    int hp = 100;

public:
    static void PrintHp(const Player& player)
    {
        std::cout << player.hp << '\n';
    }
};

Player player;
Player::PrintHp(player);
```
여기서는 `this`를 사용하는 것이 아니라, 매개변수로 전달받은 `player` 객체를 사용한다.
### 오답 해설
- **A. static 함수는 private 멤버에 접근할 수 없기 때문이다.**
	틀렸다. `static` 멤버 함수도 클래스의 멤버이므로 접근 지정자의 권한을 가진다. 따라서 `private static` 멤버에 직접 접근할 수 있고, 객체를 명시적으로 전달받으면 그 객체의 `private` 인스턴스 멤버에도 접근할 수 있다. 문제는 접근 권한이 아니라 **특정 객체가 자동으로 주어지지 않는다는 것**이다.
- **C. ****`this`**** 포인터는 오직 생성자에서만 사용할 수 있다.**
	틀렸다. `this`는 생성자뿐 아니라 `static`이 아닌 일반 멤버 함수에서도 사용할 수 있다.
- **D. static 함수는 반환 타입이 void이기 때문이다.**
	틀렸다. `static` 멤버 함수도 원하는 반환 타입을 가질 수 있다.
```plain text
static int GetCount()
{
    return 10;
}
```
### 한 줄 정리
> `this`는 “현재 객체”를 가리키지만, `static` 멤버 함수에는 현재 객체가 없기 때문에 `this`도 없다.
## ✅ 복습 체크
- [x] 강의 완주
- [x] 코드 직접 따라 침
- [x] 복습 1회
- [ ] 복습 2회 (OOP 핵심 섹션은 2회 복습)
