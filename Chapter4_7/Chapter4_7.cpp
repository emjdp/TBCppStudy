// Chapter4_7.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 비트단위 연산자

#include <iostream>
#include <bitset>
int main()
{
    using namespace std;
    // << left shift
    // >> right shift
    // ~ , & , |, ^

    unsigned int a = 3;
    cout << std::bitset<8>(a) << " " << a << endl;

    cout << std::bitset<8>(a << 1) << " " << (a << 1) << endl;
    cout << std::bitset<8>(a << 2) << " " << (a << 2) << endl;
    cout << std::bitset<8>(a << 3) << " " << (a << 3) << endl;
    cout << std::bitset<8>(a << 4) << " " << (a << 4) << endl;

    unsigned int b = 1024;
    cout << std::bitset<16>(b) << " " << b << endl;

    cout << std::bitset<16>(b >> 1) << " " << (b >> 1) << endl;
    cout << std::bitset<16>(b >> 2) << " " << (b >> 2) << endl;
    cout << std::bitset<16>(b >> 3) << " " << (b >> 3) << endl;
    cout << std::bitset<16>(b >> 4) << " " << (b >> 4) << endl;

    cout << std::bitset<16>(~b) << " " << (~b) << endl; // ! = logical not. ~ = bitwise not

    unsigned int c = 0b1100;
    unsigned int d = 0b0110;
    
    cout << c << " " << d << endl;
    cout << std::bitset<4>(c & d) << endl; // bitwise AND
    cout << std::bitset<4>(c | d) << endl; // bitwise OR
    cout << std::bitset<4>(c ^ d) << endl; // bitwise XOR

    // c &= d;
    
    cout << std::bitset<8>(d >> 2) << " " << (d >> 2) << endl; // 9가 아니라 1이 됨. 벗어나면 사라짐


    return 0;
}

