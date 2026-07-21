// Chapter3_9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MY_CONSTANTS.h"
// #define PRICE_PER_ITEM 30 // c++에서는 c처럼 이런 매크로로 이런 목적으로 안씀 const int price_per_item = 30; 이렇게 씀
using namespace std;

void printNumber(const int my_number) // const int& 으로 쓰는 경우가 더 많음
{
    // my_number = 456; 이딴식으로 하지 X 차라리 복사 해서. 방지하기 위해서 const int로 하기도 함
    int n = my_number;
    cout << n << endl;
}

int main()
{
    printNumber(123);
    const double gravity{ 9.8 }; // 이니셜라이저 꼭 해줘야 함


    const int my_const(123); // 컴파일 타임 상수. 컴파일 할때 이미 정해짐
    int number;
    cin >> number;

    const int special_number(number); // 실행할때 결정. 런타임에서 결정 되는 상수.
    cout << number << endl;
    // 이를 구분하기 힘들기 때문에 다음과 같은것이 존재
    constexpr int my_exconst(123); // 컴파일 할때 결정됬는지 체크함

    double radius;
    cin >> radius;

    double circumference = 2.0 * radius * constants::pi;
    cout << circumference << endl;
    return 0;
}
