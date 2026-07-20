// Chapter3_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 기본 자료형

#include <iostream>
#include <bitset>

int main()
{
    using namespace std;

    int c, d, e;
    int j = 3; 
    // int j(3); direct initialization
    // int j{ 3 } uniform initialization
    int p = (int)3.1415; // copy initialization
    //int p(3.14); //warning C4244: 'initializing': conversion from 'double' to 'int' 경고 뜨지만 컴파일은 됨 3으로 바꾸면서 짤림.
    //int p{ 3.14 }; //error C2397: conversion from 'double' to 'int' requires a narrowing conversion 아예 애러. 더 엄격

    int i = -1;
    int k = 123;
    char a = 'H';
    bool bValue = true;
    char chValue = 65;
    //float fValue = 3.141592; // warning C4305: 'initializing': truncation from 'double' to 'float' 더 정밀한거에 정밀하지 않을걸 넣어서.
    float fValue = 3.141592f;
    double dValue = 3.121592;
    auto aValue1 = 3.141592;
    auto aValue2 = 3.141592f;

    //char chValue = 'A';

    cout << sizeof(aValue1) << endl;
    cout << sizeof(aValue2) << endl;
    cout << sizeof(bValue) << endl;
    cout << fValue << endl;
    cout << dValue << endl;
    cout << chValue << endl;
    cout << (bValue ? 1 : 0) << endl;
    cout << (uintptr_t)static_cast<void*>(&a) << endl;
    cout << (uintptr_t)static_cast<void*>(&i) << endl;

    return 0;
}
