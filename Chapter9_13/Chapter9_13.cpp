// Chapter9_13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class A
{
public:
    int m_value;

    A(const int& input)
        : m_value(input)
    {
        cout << "Cpnstructor" << endl;
    }

    ~A()
    {
        cout << "Destructor" << endl;
    }

    void print100()
    {
        cout << m_value * 100 << endl;
    }
};

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

    //A a(1);
    //a.print100();
    //A(1).print100();
    //cout << endl;

    cout << add(Cents(6), Cents(8)).getCents();
    return 0;
}

