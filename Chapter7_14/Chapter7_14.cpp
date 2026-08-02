// Chapter7_14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void doSomething(int n)
{
    n = 10;
    cout << &n << " In do something" << " " << n << endl;
}

void doSomething2(int &n) // 레퍼런스로 받음
{
    n = 10;
    cout << &n << " In do something" << " " << n << endl;
}

void printElements(int(&arr)[5])
{
    for (int i = 0; i < 5; ++i)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}

struct Something
{
    int v1;
    float v2;
};

struct Other
{
    Something st;
};

int main()
{
    int value = 5;

    int* ptr = nullptr;
    ptr = &value;

    int &ref = value;

    cout << ref << endl; // 5

    ref = 10;
    cout << value << " " << ref << endl; // 10 10
    cout << &value << " " << &ref << " " << ptr << " " << &ptr << endl;

    const int y = 8;
    //int &ref = y; //같은건 불가능한 레프에서 y의 값을 바꿔버릴 수도 있기 때문.



    int n = 5;
    cout << n << endl;

    doSomething(n);

    cout << n << endl; // 함수 영향 없음
    cout << &n << endl;

    doSomething2(n); // 레퍼런스로 넘겼기 때문에 변수 자체가 넘어가기 때문에 주소조차도 복사 할 필요가 없음

    cout << n << endl;
    cout << &n << endl;



    const int lenght = 5;
    int arr[lenght] = { 1,2,3,4,5 };
    printElements(arr);


    Other ot;
    //ot.st.v1 = 1.0; // 비효율
    int &v1 = ot.st.v1;
    v1 = 1;

    return 0;
}

