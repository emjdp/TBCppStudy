// Chapter2_9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

namespace MySpace1
{
    namespace InnerSpace
    {
        int my_function()
        {
            return 0;
        }
    }
    int doSomething(int a, int b)
    {
        return a + b;
    }
}

namespace Myspace2
{
    int doSomething(int a, int b)
    {
        return a * b;
    }
}

using namespace std;

int main()
{
    using namespace MySpace1;
    doSomething(3, 4);
    MySpace1::InnerSpace::my_function();
    InnerSpace::my_function(); // using namespace MySpace1; 이거 해줘서 가능. 바로 my_function() 하려면 다음이 필요
    // using namespace MySpace1::InnerSpace;
   /* 
    cout << MySpace1::doSomething(3, 4) << endl;
    cout << MySpace2::doSomething(3, 4) << endl;
   */
}
