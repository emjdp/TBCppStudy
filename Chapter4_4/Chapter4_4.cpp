// Chapter4_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
// sizeof, 쉼표 연산자, 조건(부) 연산자

#include <iostream>

int main()
{
    using namespace std;

    float a;

    sizeof(float); // sizeof는 함수가 아니라 오퍼레이터
    sizeof(a); // sizeof a; 로도 가능. 변수만 됨.

    // comma operator

    int x = 3;
    int y = 10;
    //int z = (++x, ++y); // 이거랑 동치는 다음과 같음
    ++x;
    ++y;
    int z = y;
    cout << x << " " << y << " " << z << endl;


    int b = 1, c = 10;  // 여기서 콤마는 구분해주는 기호
    int d;
    d = b, c;

    cout << d << endl; // 1. (d = b), c로 실행됬던거 = 우선순위가 , 우선순위보다 먼저. d = (b , c)로 하면 10.
    // ex d = (++b, b + c);


    // conditional operator (arithmetric if)
    bool onSale = true;

    int price;




    return 0;
}

