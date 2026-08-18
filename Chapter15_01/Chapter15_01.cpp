// Chapter15_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // try, catch, throw
    double x;
    cin >> x;

    try 
    {
        if (x < 0.0) throw std::string("Negative input");

        cout << std::sqrt(x) << endl;
    }
    catch (std::string error_message)
    {
        cout << error_message << endl;
    }

    return 0;
}

