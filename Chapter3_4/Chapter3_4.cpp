// Chapter3_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 무치형 (void)

#include <iostream>

void my_function()
{

}

int main()
{
    //void my_void; // 사이즈가 지정되지 않아서 쓰면 애러남
    int i = 123;
    float f = 123.456f;

    void *my_void;

    my_void = (void*)&i; // 각각의 데이터 타입의 첫 주소의 규격은 동일 어떤건 301호 어떤건 401호~408호 여도 첫 주소 규격은 일치함
    my_void = (void*)&f; // 주소를 표현하는 데이터의 양은 같다! 그래서 둘다 void*로 캐스팅(형 변환) 할 수 있음


    return 0;
}
