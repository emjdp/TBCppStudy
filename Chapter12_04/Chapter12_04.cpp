// Chapter12_04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Mother
{
private:
    int m_i;

public:
    Mother(const int& i_in = 0)

        : m_i(i_in)
    {
        cout << "Mother construction" << endl;
    }
};

class Child : public Mother
{
private:
    float m_d;

public:
    Child()
        :m_d(1.0f)
    {
        cout << "Child construction" << endl;
    }
};


class A
{
public:
    A(int a)
    {
        cout << "A : " << a << endl;
    }

    ~A()
    {
        cout << "Destructor A" << endl;
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

    ~B()
    {
        cout << "Destructor B" << endl;
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

    ~C()
    {
        cout << "Destructor C" << endl;
    }
};

int main()
{
    Child c1; // Mother 생성자 후 Child 생성자. // 사실상 

    cout << sizeof(Mother) << endl;
    cout << sizeof(Child) << endl;



    C c(1024, 3.14, 'a');
    return 0;
}