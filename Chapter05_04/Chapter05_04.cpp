// Chapter05_04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

auto add(int x, int y)
{
    return x + y;
}

//auto add(double x, double y)
//{
//    return x + y;
//}

// template 으로 아무거나 받아오는 걸 만들 수 있음.

int main()
{
    using namespace std;

    auto a = 123;
    auto d = 123.0;
    auto c = 1 + 2.0;
    auto result = add(1, 2);

    return 0;
}

