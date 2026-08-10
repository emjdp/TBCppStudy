// Chapter07_08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void printArray(int array[]) // int *array 같음
{
    cout << sizeof(array) << endl;
    *array = 100; // 함수 밖에서도 바뀜
}

struct MyStruct
{
    int array[5] = { 9,7,5,3,1 };
};

int main()
{

    int array[5] = { 9,7,5,3,1 };
    cout <<"size : " << sizeof(array) << endl;
    cout << array[0] << " " << array[1] << endl;
    cout << array << endl;
    cout << &array[0] << endl; // array 랑 같음. array는 사실상 포인터
    cout << *array << endl;

    char name[] = "jackjack";
    cout << name << endl;
    cout << *name << endl;

    int *ptr = array;
    cout << "size : " << sizeof(ptr) << endl;
    cout << ptr << endl;
    cout << *ptr << endl;

    printArray(array); // 20아니고 8나옴. 함수 안에서도 내부적으로는 포인터.
    cout << *array << endl;

    MyStruct ms;
    cout << ms.array[0] << endl;
    return 0;
}

