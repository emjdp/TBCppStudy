// Chapter12_03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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


class A
{
public:
    A(int a)
    {
        cout << "A: " << a << endl;
    }
};

class B : public A
{
public:
    B(int a, double b)
        : A(a)
    {
        cout << "B : " << b << endl;
    }
};

class C : public B
{
public:
    C(int a, double b, char c)
        : B(a, b)
    {
        cout << "C : " << c << endl;
    }
};

int main()
{
    Child c1;

    C c(1024, 3.14, 'a');

    return 0;
}

