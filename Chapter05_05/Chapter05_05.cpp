// Chapter05_05.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 형변환

#include <iostream>
#include <typeinfo>
#include <iomanip>

int main()
{
    using namespace std;

    float a = 1.0f;
    double d = a; // numeric promotion
    
    // numeric conversion
    int i = 30000;
    char c = i;

    double x = 0.123456789;
    float y = x;

    cout << static_cast<int>(c) << endl; // 48
    cout << std::setprecision(12) << y << endl;

    cout << typeid(a).name() << endl;

    cout << 5u - 10; // 4294967291 // unsigned int가 int보다 우선 순위라 결과도 unsigned int(부호 없는 정수)로 나옴
    //bool / char / short < int < unsigned int < long < unsigned long < long long < unsigned long long < float < double < long double


    // 명시적 형변환
    int u = static_cast<int>(4.0);

    return 0;
}
