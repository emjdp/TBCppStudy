// Chapter10_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 산술 연산자 오버로딩 하기

#include <iostream>
using namespace std;

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents) { m_cents = cents; }
    int getCents() const { return m_cents; }
};

int main()
{
    Cents cents1(6);
    Cents cents2(8);

    return 0;
}

