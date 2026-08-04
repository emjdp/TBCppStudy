// Chapter8_6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

inline int min(int x, int y) // 써도 그만 안써도 그만
{
    return x > y ? y : x;
}

int main()
{
    cout << min(5, 6) << endl; // cout << (5 > 6 ? 6 : 5) << endl; 로 바뀜
    cout << min(3, 2) << endl;
}

