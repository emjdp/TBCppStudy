// Chapter09_07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Simple
{
private:
    int m_id;

public:
    Simple(int id)
    {
        setID(id); // this -> setID(id) 가 숨어 있음

        cout << this << endl; // 자기 주소를 출력
    }

    void setID(int id) { m_id = id; }

    int getID() { return m_id; }
};

class Calc
{
private:
    int m_value;

public:
    Calc(int init_value)
        : m_value(init_value)
    { }

    Calc& add(int value) { m_value += value; return *this; }
    Calc& sub(int value) { m_value -= value; return *this; }
    Calc& mult(int value) { m_value *= value; return *this; }

    void print()
    {
        cout << m_value << endl;
    }
};

int main()
{
    Simple s1(1), s2(2);
    s1.setID(2);
    s2.setID(4);

    cout << &s1 << " " << &s2 << endl;


    Calc cal(10);
   /* cal.add(10);
    cal.sub(1);
    cal.mult(2);*/
    cal.add(10).sub(1).mult(2).print();

    //cal.print();

    return 0;
}

