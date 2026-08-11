// Chapter10_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 산술 연산자 오버로딩 하기

#include <iostream>
using namespace std;

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents = 0) { m_cents = cents; }
    int getCents() const { return m_cents; }
    int& getCents() { return m_cents; }

    /*friend Cents operator + (const Cents& c1, const Cents& c2)
    {
        return Cents(c1.getCents() + c2.getCents());
    }*/
    Cents operator + (const Cents& c2)
    {
        return Cents(this->m_cents + c2.m_cents);
    }
};

/*
Cents add(const Cents& c1, const Cents& c2)
{
    return Cents(c1.getCents() + c2.getCents());
}

Cents operator + (const Cents& c1, const Cents& c2)
{
    return Cents(c1.getCents() + c2.getCents());
}
*/

int main()
{
    Cents cents1(6);
    Cents cents2(8);

    //cout << add(cents1, cents2).getCents() << endl;
    cout << (cents1 + cents2 + Cents(16)).getCents() << endl;

    return 0;
}

