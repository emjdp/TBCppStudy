// Chapter4_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 증감 연산자

#include <iostream>

int add(int a, int b)
{
    return a + b;
}

int main()
{
    using namespace std;

    int x = 6, y = 6;
    cout << x << " " << y << endl; // 6 6
    cout << ++x << " " << --y << endl; // 7 5
    cout << x << " " << y << endl; // 7 5
    cout << x++ << " " << y-- << endl; // 7 5
    cout << x << " " << y << endl; // 8 4

    int p = 1;
    int v = add(p, ++p); // do not use

    cout << v << endl;

    return 0;
}
