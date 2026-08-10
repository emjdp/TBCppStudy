// Chapter08_13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    //semantic errors

    int x;
    cin >> x;

    if (x >= 5) // = 빼야함
        cout << "x is greater than 5" << endl;

    //violated assumption

    string hello = "Hello, my name is Jack Jack";

    cout << "Input from 0 to " << hello.size() - 1 << endl;

    while (true)
    {
        int ix;
        cin >> ix;

        if (ix >= 0 && ix <= hello.size() - 1)
        {
            cout << hello[ix] << endl;
            break;
        }
        else
            cout << hello[ix] << endl;
    }
    

    return 0;
}

