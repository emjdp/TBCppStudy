// Chapter2_8.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 헤더 가드

#include <iostream>
#include "my_work.h"
#include "add.h" //여기서 하면 add가 두번 들어와서 오류 생김. 이를 방지하기 위해 #pragma once 혹은 다음과 같이 함
/* add.h
#ifndef MY_ADD
#define MY_ADD
int add(int a, int b)
{
    return a + b;
}

#endif
*/

int main()
{
    doSomething();

    return 0;
}
