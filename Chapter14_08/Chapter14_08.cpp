// Chapter14_08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template<class T>
class A
{
private:
    T m_value;

public:
    A(const T& input)
        : m_value(input)
    {
    }

    template<typename TT>
    void doSomething()
    {
        cout << typeid(T).name() << " " << typeid(TT).name() << endl;
    }

    template<typename TTT>
    void doSomething2(const TTT & input)
    {
        cout << typeid(T).name() << " " << typeid(TTT).name() << endl;
        cout << (TTT)m_value << endl;
    }

    void print()
    {
        cout << m_value << endl;
    }
};


int main()
{
    A<int> a_int(123);
    a_int.print();

    a_int.doSomething<float>();

    A<int> b_int(456);
    b_int.doSomething2(12.3);
    b_int.doSomething2('A');

    return 0;
}
