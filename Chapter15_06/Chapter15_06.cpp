// Chapter15_06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
using namespace std;

/*class A
{
public:
    ~A()
    {
        throw "error"; // 소멸자에서는 예외를 만들 수 없음
    }
};*/

int main()
{
    try
    {
        int* i = new int[1000000];
        //unique_ptr<int> up_i(i); // 스마트 포인터로 메모리 누수 방지 가능

        //do something with i
        throw "error";

        delete[] i;

        //A a;
    }

    catch (...)
    {
        cout << "Catch" << endl;
    }

    return 0;
}

