// Chapter4_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
// sizeof, 쉼표 연산자, 조건(부) 연산자

#include <iostream>

int getPrice(bool onSale)
{
    if (onSale)
        return 10;
    else
        return 100;
}

int main()
{
    using namespace std;

    float a;

    sizeof(float); // sizeof는 함수가 아니라 오퍼레이터
    sizeof(a); // sizeof a; 로도 가능. 변수만 됨.

    // comma operator

    int x = 5;
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

    //const int price = (onSale == true) ? 10 : 100;

    const int price = getPrice(onSale); // 예전에는 위에걸 했는데 컴파일러가 최적화 해주고 로그 시맨틱도 생겨서. 복잡할 때는 삼항 연산자 대신 함수로

    /* int price;

    if (onSale)
        price = 10;
    else
        price = 100; */
    
    cout << price << endl;

    // cout << x % 2 == 0 ? "even" : "odd" << endl; // 안되는 이유는?
    // (cout << (x % 2 == 0)) ? "even" : ("odd" << endl); 이렇게 해석해 버림.
    cout << ((x % 2 == 0) ? "even" : "odd") << endl;


    return 0;
}

