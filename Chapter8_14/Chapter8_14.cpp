// Chapter8_14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
#include <array>
using namespace std;

void printValue(const std::array<int, 5>& my_array, const int& ix)
{
    assert(ix >= 0);
    assert(ix <= my_array.size() - 1);

    std::cout << my_array[ix] << std::endl;
}

int main()
{
    //assert(false); // 디버그 모드에서만 작동
/*
    int number = 4;
    // ...
    assert(number == 5);

    const int x = 4
    static_assert(x == 4, "x should be 5"); // 컴파일 타임에 결정되어야 쓸 수 있음
*/
    std::array<int, 5> my_array{ 1,2,3,4,5 };
    printValue(my_array, 100);

    return 0;
}

