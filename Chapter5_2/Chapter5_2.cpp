// Chapter5_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyConstants.h"
using namespace std;
/*
    int g_x; // external linkage
    static int g_x; // internal linkage
    const int g_x; // X . 초기화 해줘야함.

    extern int g_z;
    extern const int g_z; // 다른곳에서 초기화 해주면 됨.

    int g_y(1);
    static int g_y(1); // 외부에서는 못 씀.
    const int g_y(1);

    extern int g_w(1); // 다른곳에서는 초기화 하면 안 됨.
    extern const int g_w(1);
*/
int value = 123;
static int g_a = 1; // 다른 cpp 파일에서 접근 불가


void doSomething()
{
    //int a = 1;
    static int a = 1; // 이럴거면 왜 전역으로 안하고? -> static은 메모리가 static이라는 소리. 초기화 1회.
    ++a;
    cout << a << endl;
}

// forward declaration
extern void doSomething2(); // extern 안써도 됨.
extern int a;

int main()
{
    cout << value << endl; // 123
    int value = 1;
    cout << ::value << endl; // 123
    cout << value << endl; // 1

    doSomething();
    doSomething();
    doSomething();
    doSomething();

    doSomething2();
    cout << a << endl;
    
    cout << "In main.cpp file " << Constants::pi << " " << &Constants::pi << endl;

    return 0;
}

