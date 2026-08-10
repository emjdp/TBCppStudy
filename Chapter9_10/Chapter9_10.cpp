// Chapter9_10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int generateID()
{
    static int s_id = 0;
    return ++s_id;
}

class Something
{
public:
    static int s_value;
};

int Something::s_value = 1;

int main()
{
    cout << generateID() << endl;
    cout << generateID() << endl;
    cout << generateID() << endl;
    cout << generateID() << endl;

    cout << &Something::s_value << " " << Something::s_value << endl;

    Something st1;
    Something st2;

    st1.s_value = 2;

    cout << &st1.s_value << " " << st1.s_value << endl;
    cout << &st2.s_value << " " << st2.s_value << endl;

    Something::s_value = 1024;
    cout << &Something::s_value << " " << Something::s_value << endl;

    return 0;
}

