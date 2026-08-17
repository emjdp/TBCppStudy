// Chapter13_03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class A
{
public:
    virtual void print() { cout << "A" << endl; }
};

class B : public A
{
public:
    void print() override final { cout << "B" << endl; } // override 키워드는 실수 방지용
    //virtual void print() { cout << " B " << endl; }
};

class C : public B
{
public:
    //virtual void print() { cout << " C " << endl; } // fianl 키워드로 오버라이드 불가
};


class A1
{
public:
    void print() { cout << "A1" << endl; }
    virtual A1* getThis()
    {
        cout << "A::getThis()" << endl;
        return this;
    }
};

class B1 : public A1
{
public:
    void print() { cout << "B1" << endl; }
    virtual B1* getThis() 
    {
        cout << "B::getThis()" << endl;
        return this; 
    }
};

int main()
{
    A a;
    B b;

    A& ref = b;
    ref.print();

    cout << endl;

    A1 a1;
    B1 b1;
    A1 &ref1 = b1;
    b1.getThis()->print(); 
    ref1.getThis()->print(); // print는 가상함수가 아니므로 a1이 출력됨

    cout << typeid(b1.getThis()).name() << endl;
    cout << typeid(ref1.getThis()).name() << endl;


    return 0;
}

