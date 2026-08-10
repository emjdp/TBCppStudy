// Chapter07_09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    //int value = 7;
    //int *ptr = &value; //4씩

    double value = 7;
    double *ptr = &value; //8씩

    cout << uintptr_t(ptr - 1) << endl;
    cout << uintptr_t(ptr) << endl;
    cout << uintptr_t(ptr + 1) << endl;
    cout << uintptr_t(ptr + 2) << endl;


    int array[] = { 9,7,5,3,1 };

    int* ptr1 = array;
    //cout << array[0] << " " << (uintptr_t)&array[0] << endl;
    //cout << array[1] << " " << (uintptr_t)&array[1] << endl;
    //cout << array[2] << " " << (uintptr_t)&array[2] << endl;
    //cout << array[3] << " " << (uintptr_t)&array[3] << endl;
    for (int i = 0; i < 5; i++)
    {
        //cout << array[i] << " " << (uintptr_t)&array[i] << endl;
        cout << *(ptr1 + i) << " " << (uintptr_t)(ptr1 + i) << endl;
    }

    char name[] = "Jack Jack";

    const int n_name = sizeof(name) / sizeof(char);

    for (int i = 0; i < n_name; ++i)
    {
        cout << *(name + i);

    }
    return 0;
}

