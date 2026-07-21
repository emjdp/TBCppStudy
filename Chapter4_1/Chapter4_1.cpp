// Chapter4_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x = 4 / 2 * 3; // Associativity Left-to-right
    // ^ 가 제곱으로 안 쓰임. bitwise XOR
    int y = std::pow(2, 3);
    cout << y << endl;
    return 0;
}

