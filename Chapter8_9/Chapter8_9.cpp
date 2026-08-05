// Chapter8_9.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 함수 포인터

#include <iostream>
#include <array>

using namespace std;


int main()
{
    std::array<int, 10> my_array{ 0,1,2,3,4,5,6,7,8,9 };

    for (auto element : my_array)
    {
        if (element % 2 == 0) cout << element;
    }
    cout << endl;


    return 0;
}

