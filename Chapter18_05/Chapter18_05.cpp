// Chapter18_05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1("one");

    string str2;
    str2 = str1;
    str2 = "two";
    str2.assign("two").append(" ").append("three");

    cout << str1 << " " << str2 << endl;

    std::swap(str1, str2);

    cout << str1 << " " << str2 << endl;

    str1.swap(str2);

    cout << str1 << " " << str2 << endl;

    str1.append("three");

    str1 += "three";

    str1 = str2 + "four";

    cout << str1 << endl;

    str1.push_back('A');

    cout << str1 << endl;

    str1.insert(2, "aaaaa");
    cout << str1 << endl;

    return 0;
}

