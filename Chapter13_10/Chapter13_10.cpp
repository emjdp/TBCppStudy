// Chapter13_10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
    int m_i = 0;

    virtual void print()
    {
        cout << "I'm Base" << endl;
    }
};

class Derived1 : public Base
{
public:
    int m_j = 1024;

    virtual void print() override
    {
        cout << "I'm derived" << endl;
    }
};

class Derived2 : public Base
{
public:
    string m_name = "Dr. Two";

    virtual void print() override
    {
        cout << "I'm derived" << endl;
    }
};

int main()
{
    Derived1 d1;
    d1.m_j = 2048;

    Base* base = &d1;
    // base.m_j 접근불가

    auto* base_to_d1 = dynamic_cast<Derived1*>(base); // 동적 형변환
    cout << base_to_d1->m_j << endl; // 접근 가능
    base_to_d1->m_j = 256;

    cout << d1.m_j << endl;

    return 0;
}


