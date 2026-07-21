// Chapter3_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 고정 너비 정수 / 나중에 멀티 플랫폼 프로그래밍을 한다면 많이 쓰는.

#include <iostream>
//#include <cstdint> // iostream에서 인클루드 해줌

int main()
{
    using namespace std;

    std::int16_t i(5); // 2 bytes
    std::int8_t myint = 65; // char A

    cout << myint << endl;

    std::int_fast8_t fi(5);
    std::int_least64_t fl(5);

}
