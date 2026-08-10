// Chapter06_04.cpp : This file contains the 'main' function. Program execution begins and ends there.
// goto 

#include <iostream>
#include <cmath> // sqrt()

using namespace std;

int main()
{
    double x;

tryAgain : // label
    cout << "Enter a non-negative number" << endl;
    cin >> x;

    if (x < 0.0)
        goto tryAgain; // 잘 안쓰임

    cout << sqrt(x) << endl;
    
/*    goto skip; // 순서가 잘못됨.
    int y = 5;

skip:
    y += 3;*/

    return 0;
}

