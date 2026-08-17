// Chapter12_05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

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

int main()
{
    Base base;

    Derived derived;
    derived.m_public = 1024;

    return 0;
}

