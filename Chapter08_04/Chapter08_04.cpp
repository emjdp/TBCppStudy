// Chapter08_04.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 주소에 의한 인수 전달

#include <iostream>
using namespace std;

void foo(double degrees, double *sin_out, double *cos_out)
{
    *sin_out = 1.0;
    *cos_out = 2.0;
}

int main()
{
    double degrees = 30;
    double sin, cos;

    foo(degrees, &sin, &cos);

    cout << sin << " " << cos << endl;
    
    return 0;
}

