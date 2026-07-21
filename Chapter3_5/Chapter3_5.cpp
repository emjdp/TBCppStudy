// Chapter3_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

int main()
{
    using namespace std;

    double d(0.1);
    double d1(1.0);
    double d2(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);

    cout << d << endl; // 0.1
    cout << d1 << endl; // 1
    cout << d2 << endl; // 1
    cout << std::setprecision(17);
    cout << "---------------------" << endl;
    cout << d << endl; // 0.10000000000000001
    cout << d1 << endl; // 1
    cout << d2 << endl; // 0.99999999999999989

    float f(3.141592f); // 3.14159로 변환됨
    float s(123456789.0f); // 10 significant digits 유효숫자 10개
    cout << 31.4e-1 << endl;
    cout << std::setprecision(16);
    cout << 1.0 / 3.0 << endl;
    cout << s << endl; // 123456792
    cout << "---------------------" << endl;

    double zero = 0.0;
    double posinf = 5.0 / zero;
    double neginf = -5.0 / zero;
    double nan = zero / zero;
    
    cout << posinf << " " << std::isinf(posinf) << endl; // inf 1
    cout << neginf << " " << std::isinf(neginf) << endl; // -inf 1
    cout << nan << " " << std::isnan(nan) << endl; // -nan(ind) 1
    cout << 1.0 << " " << std::isnan(1.0) << endl; 




    long double ld;

    cout << sizeof(f) << endl;
    cout << sizeof(d) << endl;
    cout << sizeof(ld) << endl;

    cout << numeric_limits<float>::max() << endl;
    cout << numeric_limits<double>::max() << endl;
    cout << numeric_limits<long double>::max() << endl;

    cout << numeric_limits<float>::min() << endl;
    cout << numeric_limits<double>::min() << endl;
    cout << numeric_limits<long double>::min() << endl; // min 은 표현할 수 있는 제일 작은 값의 절대값

    cout << numeric_limits<float>::lowest() << endl;
    cout << numeric_limits<double>::lowest() << endl;
    cout << numeric_limits<long double>::lowest() << endl;

    return 0;
}

