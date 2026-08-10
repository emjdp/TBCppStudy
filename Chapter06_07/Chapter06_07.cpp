// Chapter06_07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int pow(int base, int exponent)
{
    int result = 1;

    for (int count = 0; count < exponent; ++count)
        result *= base;
    return result;
}
int main()
{
    int count = 0;
    for (; count < 10; ++count) // iteration // int count = 0 밖에 빼두고 비워도 됨
    {
        cout << count << endl;
    }
    cout << count << endl;

    for (int i = 9; i >= 0; i -= 2)
    {
        cout << i << endl;
    }

    for (int i = 0, j = 0;i < 10; ++i, j += 2)
    {
        cout << i << " " << j << endl;
    }
    return 0;
}

