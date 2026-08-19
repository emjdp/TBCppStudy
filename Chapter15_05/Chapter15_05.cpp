// Chapter15_05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class A
{
private:
    int m_x;
public:
    A(int x) : m_x(x)
    {
        if (x <= 0)
            throw 1;
    }
};

class B : public A
{
public:
    //B(int x)
    //    : A(x)
    //{
    //}
    // 여기서 바로 캐치하고 싶으면

    B(int x) try : A(x)
    {
        //do initialization
    }
    catch (...)
    {
        cout << "Catch in B contructor" << endl;
        //throw;
    }
}; 


/*void doSomething()
try
{
    throw - 1;
}
catch (...)
{
    cout << "Catch in doSomething()" << endl;
}*/


int main()
{
    try
    {
        //doSomething();
        B b(0);
    }
    catch (...)
    {
        cout << "catch int main()" << endl;
    }

    return 0;
}

