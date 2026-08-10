// Chapter08_10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int* ptr = nullptr;
    ptr = new int[1000000];
    
    delete[] ptr;

    return 0;
}

