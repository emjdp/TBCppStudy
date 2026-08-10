// Chapter09_12.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 친구 함수와 클래스 friend

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

