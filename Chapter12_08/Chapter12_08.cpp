// Chapter12_08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

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

int main()
{
    Derived derived(7);

    derived.m_i = 10;
    //derived.print();

    return 0;
}

