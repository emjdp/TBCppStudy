// Chapter8_7.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 함수 오버로딩

#include <iostream>
#include <string>

using namespace std;

typedef int my_int;


//void print(const char *value) {}
//void print(int value) {}
void print(unsigned int value) {}
void print(float value) {}

int add(int x, int y)
{
    return x + y;
}

int add(double x, double y)
{
    return x + y;
}

int main()
{
    add(1, 2);
    add(3.0, 4.0);

    //print('a');
    //print(0);
    //print(3.141592);

    // 모호성 제거
    print((unsigned int)'a');
    print(0u);
    print(3.14159f);

    return 0;
}

