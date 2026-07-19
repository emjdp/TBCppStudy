// Chapter2_6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int add(int x, int y)
{
    return x + y; // 여백. indenting
}

int main()
{
    int x = 2; // x 는 variable, = 은 Assignment, 2 는 literal
    cout << x + 2 << endl; // x + 2 : 피연산자 Operand
    cout << -x << endl; // 단항 연산자
    cout << 1 + 2 << endl; // 이항 연산자
    int y = (x > 0) ? 1 : 2; // 삼항 연산자, x가 0보다 크면(참이면) 왼쪽거 실행 y = 1
    cout << y << endl;
    cout << "My Home" << "and my name is" << "hoo" << 
        "asdlfjsal" << endl;
    int my_v        = 1;
    int p           = 23;
    int num_apples  = 1243;
}

