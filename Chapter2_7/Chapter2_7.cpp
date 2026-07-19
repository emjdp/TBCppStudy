// Chapter2_7.cpp : This file contains the 'main' function. Program execution begins and ends there.
// error LNK2019: unresolved external symbol "int __cdecl addpp(int,int)" (?addpp@@YAHHH@Z) referenced in function main
// ide에 add.cpp 를 작업환경에서 빼두면 위와 같이 링킹 에러가 발생
#include <iostream>
#include "MyHeaders/addpp.h"
using namespace std;

int add(int a, int b); // forward declaration 전방 선언
int multiply(int a, int b);
int subtract(int a, int b);

int main()
{
    cout << add(1, 2) << endl;
    cout << addpp(1, 2) << endl;
}

// definition
int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}

int subtract(int a, int b)
{
    return a - b;
}