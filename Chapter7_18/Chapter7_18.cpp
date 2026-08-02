// Chapter7_18.cpp : This file contains the 'main' function. Program execution begins and ends there.
// void pointer, generic pointer

#include <iostream>

using namespace std;

int main()
{
    int i = 5;
    float f = 3.0f;
    char c = 'a';

    void* ptr = nullptr;

    ptr = &c;
    ptr = &i;
    ptr = &f;
    
    //cout << ptr + 1 << endl; // void 포인터는 이거 못 씀, +1 할때 몇 바이트를 더해야 할 지 알 수 없음.

    cout << &f << " " << ptr << endl;
    //cout << *ptr << endl; // 무슨형이 있는지 알 수 없으므로 디 레퍼런싱 불가능
    cout << *static_cast<float*>(ptr) << endl;

    return 0;
}

