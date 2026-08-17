// Chapter13_04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Base
{
public:
    virtual ~Base()
    {
        cout << "~Base()" << endl;
    }
};

class Derived : public Base
{
private:
    int* m_array;

public:
    Derived(int length)
    {
        m_array = new int[length];
    }

    ~Derived() override // 키워드 없어도 작동
    {
        cout << "~Derived()" << endl;
        delete[] m_array;
    }

};
int main()
{
    //Derived derived(5);
    Derived* derived = new Derived(5);
    Base* base = derived;
    delete base; // 소멸자도 virtual이어야 derived도 지워지면서 메모리 누수 안됨

    return 0;
}

