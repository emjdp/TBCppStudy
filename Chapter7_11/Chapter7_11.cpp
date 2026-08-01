// Chapter7_11.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 메모리 동적 할당

#include <iostream>

using namespace std;

int main()
{
    //int array[1000000]; //stack // stack은 용량이 작음
    //int var;
    //var = 7;

    //int *ptr = new int;
    //*ptr = 7;
    
    int *ptr = new (std::nothrow) int{ 7 }; // 할당 실패 시 예외(bad_alloc)를 던지는 대신 nullptr을 반환

    cout << ptr << endl;
    cout << *ptr << endl;

    delete ptr; // 메모리 반납
    ptr = nullptr;
    cout << "After delete" << endl;
    if (ptr != nullptr)
    {
        cout << ptr << endl;
        cout << *ptr << endl;
    }


    return 0;
}

