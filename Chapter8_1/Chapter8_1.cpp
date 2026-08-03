// Chapter8_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int foo(int x, int y);  // 함수 선언

int foo(int x, int y)   // 함수 정의
{
    return x + y;
} // x and y are destroyed here

int main()
{
    int x = 1, y = 2;

    foo(6, 7); // 6,7 : arguments (actual parameters) 인자
    foo(x, y + 1);

    return 0;
}

