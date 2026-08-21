// Chapter18_03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    //string my_str("");
    string my_str("0123456789");
    my_str.reserve(1000);

    cout << my_str.length() << endl;

    cout << std::boolalpha;
    cout << my_str.empty() << endl;
    cout << my_str.size() << endl;
    cout << my_str.capacity() << endl;
    cout << my_str.max_size() << endl;

    return 0;
}
