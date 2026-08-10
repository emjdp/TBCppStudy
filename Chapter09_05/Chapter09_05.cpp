// Chapter09_05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

