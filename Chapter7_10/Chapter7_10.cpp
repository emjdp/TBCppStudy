// Chapter7_10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

const char* getName()
{
    return "Jack Jack";
}

int main()
{
    const char *name = "Jack Jack";
    const char *name2 = "Jack Jack";
    const char* name3 = getName();

    cout << (uintptr_t)name << endl;
    cout << (uintptr_t)name2 << endl;
    cout << (uintptr_t)name3 << endl;

    int int_arr[5] = { 1,2,3,4,5 };
    char char_arr[] = "Hello, world!";
    const char* name4 = "Jack Jack";

    cout << int_arr << endl;
    cout << char_arr << endl;
    cout << name4 << endl; // 문자열 포인터는 c 스타일의 문자형, 배열일 가능성이 높으므로 주소를 축력하는게 아니라 null char 만날때까지 출력.

    return 0;
}

