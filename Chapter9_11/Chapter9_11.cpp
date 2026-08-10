// Chapter9_11.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 정적 멤버 함수

#include <iostream>
using namespace std;

class Something
{
public:
    class _init
    {
    public:
        _init()
        {
            s_value = 9876;
        }
    };

private:
    static int s_value;
    int m_value;

public:
    static _init s_initializer;

    static int getValue()
    {
        return s_value; // this->s_value 사용 불가능
    }

    int temp()
    {
        return this->s_value;
    }
};

int Something::s_value = 1024;
Something::_init Something::s_initializer;

int main()
{
    //cout << Something::s_value << endl; // 불가능
    cout << Something::getValue() << endl; 

    Something s1, s2;
    cout << s1.getValue() << endl;


    int (Something:: * fptr1)() = &Something::temp;

    cout << (s2.*fptr1)() << endl;

    int (*fptr2)() = &Something::getValue;

    cout << fptr2() << endl;

    return 0;
}


