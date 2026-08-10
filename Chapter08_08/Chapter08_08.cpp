// Chapter08_08.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 매개변수의 기본값

#include <iostream>
#include <string>
using namespace std;

void print(int x = 10, int y = 20, int z = 30); // in header
// 기본값 설정은 위아래에서하나만
void print(int x, int y, int z)
{
    cout << x << " " << y << " " << z << endl;
}

void print1(std::string str) {}
void print1(char ch = ' ') {}

int main()
{
    print(10);
    print();

    print();

    return 0;
}

