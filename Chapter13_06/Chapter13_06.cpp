// Chapter13_06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Base
{
public:
    //FunctionPointer *_vptr;
    virtual void fun1() {};
    void fun2() {};
};

class Der : public Base
{
public:
    //FunctionPointer *_vptr;
    void fun1() {};
    void fun3() {};
};

int main()
{
    cout << sizeof(Base) << endl;
    cout << sizeof(Der) << endl;

    return 0;
}

