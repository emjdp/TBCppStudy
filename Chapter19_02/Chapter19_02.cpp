// Chapter19_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //cout.setf(std::ios::showpos);

/*    cout.unsetf(std::ios::dec);
    cout.setf(std::ios::hex);*/

    //cout.setf(std::ios::hex, std::ios::basefield);

/*    cout << std::hex << std::uppercase;
    cout << 108 << endl;*/
    
    cout.unsetf(std::ios::showpos);
    cout << 109 << endl;

    //cout << std::defaultfloat;
    cout << std::scientific;
    //cout << std::showpoint;
    cout << std::setprecision(6) << 12.45672348 << endl;

    cout << -12345 << endl;
    cout << std::setw(10) << -12345 << endl;
    cout << std::setw(10) << std::left << -12345 << endl;
    cout << std::setw(10) << std::right << -12345 << endl;
    cout << std::setw(10) << std::internal << -12345 << endl;

    return 0;
}

