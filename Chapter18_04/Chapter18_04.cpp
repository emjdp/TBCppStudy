// Chapter18_04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string my_str("abcdefg");

    cout << my_str.c_str() << endl;
    const char* arr = my_str.c_str();
    cout << arr[6] << endl;
    cout << arr[7] << endl;
    cout << (int)arr[7] << endl;

    try
    {
        //my_str[100] = 'X';
        my_str.at(100) = 'X';
    }
    catch (std::exception & e)
    {
        cout << e.what() << endl;
    }

    cout << my_str[0] << endl;
    cout << my_str[3] << endl;

    my_str[3] = 'Z';
    cout << my_str[3] << endl;
    cout << my_str << endl;


    return 0;
}

