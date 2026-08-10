// Chapter07_13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    using namespace std;

    const int value = 5;
    const int *ptr = &value;

    cout << *ptr << endl;


    int value3 = 5;
    int *const ptr1 = &value3;

    *ptr1 = 10;
    cout << *ptr1 << endl;

    int value4 = 8;
    //*ptr1 = &value4;

    int value5 = 5;
    const int* const ptr2 = &value5;
    return 0;
}

