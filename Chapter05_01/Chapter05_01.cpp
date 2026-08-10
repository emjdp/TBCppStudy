// Chapter05_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

namespace work1
{
    namespace work11
    {
        namespace work111
        {
            int a = 2;
        }
    }
    int a = 1;
    void doSomething()
    {
        a += 3;
    }
}
// nested namespace c++14 부터는 이렇게도 됨
namespace work3::work33::work333
{
    int a = 2;
}



namespace work2
{
    int a = 1;
    void doSomething()
    {
        a += 5;
    }
}

int main()
{
    using namespace std;

    int apple = 5;

    cout << apple << endl; // 5
   
    {
        int apple = 1;
        cout << apple << endl; // 1
    }

    cout << apple << endl; // 5

    work1::a;
    work1::doSomething();

    work2::a;
    work2::doSomething();

    work3::work33::work333::a;

    return 0;
}

