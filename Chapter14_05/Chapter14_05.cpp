// Chapter14_05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include "Storage8.h"

using namespace std;

template<typename T>
class A
{
public:
    A(const T& input)
    { }

    void doSomething()
    {
        cout << typeid(T).name() << endl;
    }

    void test()
    { }
};

template<>
class A<char>
{
public:
    A(const char & temp)
    { }

    void doSomething()
    {
        cout << "Char type specialization" << endl;
    }
};

int main()
{
    A a_int(1);
    A a_double(3.14);
    A a_char('a');

    a_int.doSomething();
    a_double.doSomething();
    a_char.doSomething();

    cout << endl;

    Storage8<int> intStorage;

    for (int count = 0; count < 8; ++count)
        intStorage.set(count, count);

    for (int count = 0; count < 8; ++count)
        std::cout << intStorage.get(count) << '\n';

    cout << "Sizeof Storahe8<int> " << sizeof(Storage8<int>) << endl;

    Storage8<bool> boolStorage;

    for (int count = 0; count < 8; ++count)
        boolStorage.set(count, count);

    for (int count = 0; count < 8; ++count)
        std::cout << boolStorage.get(count) << '\n';

    cout << "Sizeof Storahe8<bool> " << sizeof(Storage8<bool>) << endl;
    return 0;
}

