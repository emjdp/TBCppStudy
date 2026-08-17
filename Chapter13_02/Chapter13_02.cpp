// Chapter13_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class A
{
public:
    virtual void print(){ cout << " A " << endl; }
};

class B : public A
{
public:
    virtual void print() { cout << " B " << endl; }
};

class C : public B
{
public:
    virtual void print() { cout << " C " << endl; }
};

class D : public C
{
public:
    virtual void print() { cout << " D " << endl; }
};

int main()
{
    A a;
    B b;
    C c;
    D d;

    B& ref = c; // B는 virtual이 아니어도 A를 상속받았기 때문에 
    ref.print(); // c가 나옴

    return 0;
}

