// Chapter4_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 산술 연산자

#include <iostream>

int main()
{
    using namespace std;

    int x = 7;
    int y = 4;

    cout << x / y << endl; // 1
    cout << float(x) / y << endl; // 1.75
    cout << x / float(y) << endl; // 1.75
    cout << float(x) / float(y) << endl; // 1.75
    cout << -5 / 2 << endl; // -2 -0.5는 버림

    int  z = x;
    z += y; // z = z + y

    return 0;
}

