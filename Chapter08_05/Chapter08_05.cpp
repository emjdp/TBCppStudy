// Chapter08_05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <tuple>

using namespace std;

//int *getValue(int x)
//{
//    int value = x * 2;
//    return &value;
//}

int* allocateMemory(int size)
{
    return new int[size];
}

int& get(std::array<int, 100>& my_array, int ix)
{
    return my_array[ix];
}

std::tuple<int, double> getTuple()
{
    int a = 10;
    double d = 3.14;
    return std::make_tuple(a, d);
}

int main()
{
    //int value = *getValue(3); // 위험. 권장하지 않음
    // int* array = allocateMemory(1024);
   
    // delete[] array;
    std::array<int, 100> my_array;
    my_array[30] = 10;

    get(my_array, 30) = 1024;

    cout << my_array[30] << endl;


    //std::tuple<int, double> my_tp = getTuple();
    //cout << std::get<0>(my_tp) << endl; //a
    //cout << std::get<1>(my_tp) << endl; //d
    auto[a, d] = getTuple();
    cout << a << endl;
    cout << d << endl;

    return 0;
}

