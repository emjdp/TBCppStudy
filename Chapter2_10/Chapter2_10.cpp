// Chapter2_10.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 전처리기

#include <iostream>
#include <algorithm>
using namespace std;

#define MY_NUMBER 9
#define MAX(a,b) ((a>b) ? a : b) // 요즘은 매크로 잘 안씀
#define LIKE_APPLE // 이 파일 안에서만 영향. 그래서 Orange가 출력

void doSomething();

int main()
{
/*
#ifdef LIKE_APPLE
    cout << "Apple" << endl;
#endif 

#ifndef LIKE_APPLE
    cout << "Orange" << endl;
#endif 
*/
    doSomething();
    cout << MY_NUMBER << endl;
    cout << MAX(2,5) << endl;
    cout << std::max(1 + 3, 2) << endl;

    return 0;
}
