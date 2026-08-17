// Chapter12_07.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

    friend std::ostream& operator << (std::ostream& out, const Base& b)
    {
        out << "This is base output" << endl;
        return out;
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

    void print() // 오버라이딩
    {
        cout << "I'm derived " << endl;
    }

    friend std::ostream& operator << (std::ostream& out, const Derived& b) // output 오퍼레이터 오버라이드
    {
        cout << static_cast<Base>(b); // Base으로 형변환 해서 This is base output 출력됨
        out << "This is derived output" << endl;
        return out;
    }
};

int main()
{
    Base base(5);
    base.print();
    cout << base;

    Derived derived(7);
    derived.print();
    cout << derived;

    return 0;
}

