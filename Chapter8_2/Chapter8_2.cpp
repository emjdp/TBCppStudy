// Chapter8_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 값에 의한 전달

#include <iostream>

using namespace std;

void doSomething(int y) // y 선언 후 값 복사
{
    cout << "In func " << y << " " << &y << endl;
}

int main()
{
    doSomething(5); // 값에 의한 전달

    int x = 6;

    cout << "In main " << x << " " << &x << endl;
    doSomething(x); // x가 전달되는 것이 아니라 6이 전달됨.
    doSomething(x+1);

    return 0;
}

