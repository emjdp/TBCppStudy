// Chapter14_03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "MyArray.h"

int main()
{
    MyArray<double, 100> my_array;
    for (int i = 0; i < my_array.getLength(); ++i)
        my_array[i] = i * 10;

    my_array.print();

    return 0;
}