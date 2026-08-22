// Chapter19_03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    stringstream os;

    //os << "Hello, World!"; // << : insertion operator, >> : extraction operator
    //os.str("Hello, World!");
    //os << "Hello, World!2" << endl;
    //os.str("Hello, World!\n");

    //cout << os.str() << endl;

    /*string str;
    str = os.str();
    cout << str << endl;*/

/*    os << "12345 67.89";

    string str1;
    string str2;

    os >> str1 >> str2;

    cout << str1 << "|" << str2 << endl;*/

    int i = 12345;
    double d = 67.89;

    os << i << " " << d;

    string str1;
    string str2;

    os >> str1 >> str2;

    cout << str1 << "|" << str2 << endl;

    return 0;
}




