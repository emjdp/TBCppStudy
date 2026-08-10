// Chapter07_07a.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Null Pointer

#include <iostream>
#include <cstddef>
void doSomething(double* ptr)
{
    std::cout << "adress of pointer varaible in doSomething" << &ptr << std::endl;

    if (ptr != nullptr)
    {
        //do something useful
        std::cout << *ptr << std::endl;
    }
    else
    {
        //do nothing with ptr
        std::cout << "NULL ptr, do nothing" << std::endl;
    }

}
int main()
{
    double *ptr = 0; // c-style
/*    
    double* ptr = NULL; // c-style
    double* ptr = nullptr; // mpdern c++
    double* ptr{ nullptr }; // mpdern c++ 
*/

    doSomething(ptr);
    doSomething(nullptr);

    double d = 123.4;
    doSomething(&d);

    ptr = &d;
    doSomething(ptr);

    std::nullptr_t nptr; //nullptr 값만 넣을 수 있음

    std::cout << "adress of pointer varaible in main" << &ptr << std::endl;
    return 0;
}

