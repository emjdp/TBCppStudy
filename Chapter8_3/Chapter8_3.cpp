// Chapter8_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 참조에 의한 인수 전달

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void addOne(int &y)
{
    cout << "in fn " << y << " " << &y << endl;
    y += 1;
}
void getSinCos(const double degrees, double &sin_out, double &cos_out)
{
    static const double pi = 3.141592;

    const double radians = degrees * pi / 180.0;

    sin_out = std::sin(radians);
    cos_out = std::cos(radians);
}

typedef int* pint;
void foo(pint &ptr) // (int *&ptr) 랑 같음
{
    cout << ptr << " " << &ptr << endl;
}

void printElement(vector<int>& arr)
{

}

int main()
{
    int x = 5;
    cout << x << " " << &x << endl;

    addOne(x);

    cout << x << " " << &x << endl;

    double sin(0.0);
    double cos(0.0);

    getSinCos(30.0, sin, cos);

    cout << sin << " " << cos << endl;


    //int* ptr = &x;
    pint ptr = &x;
    foo(ptr);


    vector<int> arr{ 1,2,3,4 };
    printElement(arr);

    return 0;
}

