---
강의 수: 15
상태: 진행 중
섹션 번호: 9
섹션명: 섹션 9. 객체지향의 기초
완료일: null
완료한 강의 수: 6
중요도: ⭐⭐ OOP 핵심
진도율: 40
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
