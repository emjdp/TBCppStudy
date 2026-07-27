// Chapter6_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int min(int x, int y)
{
    //if (x > y) return y;
    //else       return x;
    return (x > y) ? y : x;
}

int main()
{
    cout << min(3, 7) << endl;
    int x;
    cin >> x;

    if (x > 10)
    {
        cout << x << " is greater than 10" << endl;
    }
    else
        cout << x << " not is greater than 10" << endl;

    if (1)
        int x = 5; // 밖에서 영향 없음
    else
        int x = 6;
    cout << x << endl;

    if (x > 10)
        cout << "x is greater than 10" << endl;
    else if (x < 10)
        cout << "x is less than 10" << endl;
    else // if (x == 10)
        cout << "x is exactly 10" << endl;

    if (x >= 10)
    {
        if (x >= 20)
            cout << "x is between 10 and 20" << endl;
        else
            cout << "..." << endl;
    }
    
    int a, b;
    cin >> a >> b;

    if (a > 0 && b > 0)
        cout << "both number are positive" << endl;
    else if (a > 0 || b > 0)
        cout << "one of the number is positive" << endl;
    else
        cout << "Neither number is positive" << endl;

    if (a > 10)
        cout << "A" << endl;
    else if (x == -1)
        return 0; // exit(0)
    else if (x < 0)
        cout << "B " << endl;

    cout << "Hello " << endl;


    if (x > 10)
        ; // null statement

    if (x = 0) // x = 0; if(x)
        cout << x << endl; // 실행 안됨
    cout << x << endl;

    return 0;
}

