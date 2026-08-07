// Chapter8_16.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 생략부호 Ellipsis

#include <iostream>
#include <cstdarg> // for ellipsis
using namespace std;

double findAverage(int count, ...)
{
    double sum = 0;

    va_list list;

    va_start(list, count);

    for (int arg = 0; arg < count; ++arg)
        sum += va_arg(list, int);

    va_end(list);

    return sum / count;
}

int main()
{
    cout << findAverage(3, 3, 5, 24, 54, 7) << endl;
    cout << findAverage(2, 3, 5, "Hello", 'c') << endl;

    return 0;
}

