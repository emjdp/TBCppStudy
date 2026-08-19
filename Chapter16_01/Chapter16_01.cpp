// Chapter16_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Resource.h"
#include "AutoPtr.h"

using namespace std;

// RAII : Resource Acquisition Is Initiallization
void doSomething()
{
    Resource* res = new Resource; // dull pointer

    // work with res
    if (true)
    {
        return; // early return // try-catch 라면 throw 하면서 delete 불가
    }

    delete res; // 실행안됨

    return;
}

void doSomething2()
{
    try
    {
        AutoPtr<Resource> res(new Resource); // smart pointer

        if (false)
        {
            throw - 1;
        }
    }
    catch (...)
    {

    }
}
int main()
{
    doSomething();
    cout << endl;
    doSomething2();
    cout << endl;

    {

        AutoPtr<Resource> res1(new Resource);
        AutoPtr<Resource> res2;

        cout << std::boolalpha;

        cout << res1.m_ptr << endl;
        cout << res2.m_ptr << endl;

        res2 = res1; // move semantics

        cout << res1.m_ptr << endl;
        cout << res2.m_ptr << endl;
    }

    // syntax vs semantics
    // value semantics (copy semantics)
    // reference semantics (pointer)
    // move semantics (move)

    return 0;

}

