// Chapter07_07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Something
{
    int a, b, c, d; // 4 x 4 =16
};

int main()
{
    int x = 5;
    double d = 123.0;
    // & : address-of operator
    // * : de-reference operator

    cout << x << endl;
    cout << &x << endl;
    cout << (int)&x << endl;

    cout << *(&x) << endl;

    //typedef int* pint;
    //pint ptr_x = &x, ptr_y = &x;
    int* ptr_x = &x, * ptr_y = &x;
    double* ptr_d = &d;

    cout << ptr_x << endl;
    cout << *ptr_x << endl;

    cout << ptr_d << endl;
    cout << *ptr_d << endl;

    cout << typeid(ptr_x).name() << endl;

    cout << sizeof(x) << endl;  // 4
    cout << sizeof(d) << endl;  // 8
    cout << sizeof(&x) << " " << sizeof(ptr_x) << endl; // 8 8
    cout << sizeof(&d) << " " << sizeof(ptr_d) << endl; // 8 8
    // 집이 크다고 해서 주소가 길지는 않다.
    Something ss;
    Something *ptr_s;
    cout << sizeof(Something) << endl;  // 4
    cout << sizeof(ptr_s) << endl;


    return 0;
}

