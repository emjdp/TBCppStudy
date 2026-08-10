// Chapter08_09.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 함수 포인터

#include <iostream>
#include <array>
#include <functional>

using namespace std;

bool isEven(const int& number)
{
    if (number % 2 == 0) return true;
    else return false;
}

bool isOdd(const int& number)
{
    if (number % 2 != 0) return true;
    else return false;
}

void printNumbers(const array<int, 10>& my_array, std::function<bool(const int&)> check_fcn)
{
    for (auto element : my_array)
    {
        if (check_fcn(element) == true) cout << element;
    }
    cout << endl;
}

int main()
{
    std::array<int, 10> my_array{ 0,1,2,3,4,5,6,7,8,9 };
    std::function<bool(const int&)> fcnptr = isEven;

    printNumbers(my_array, fcnptr);
    fcnptr = isOdd;

    printNumbers(my_array, fcnptr);



    return 0;
}

