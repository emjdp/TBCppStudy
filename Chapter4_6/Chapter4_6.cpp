// Chapter4_6.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 논리 연산자

#include <iostream>

int main()
{
    using namespace std;

    //logical AND &&
    bool x = true;
    bool y = false;

    cout << (x && y) << endl;

    //ex    
    bool hit = true;
    int health = 10;

    if (hit == true && health < 20) // if (hit && health < 20) 도 됨
    {
        cout << "die" << endl;
    }
    else
        health -= 20;

    //logical OR ||
    int v = 1;

    if (v == 0 || v == 1)
        cout << "v is 0 or 1" << endl;

    //logical NOT

    int a = 5;
    int b = 7;

    if (x != y)
    {
        cout << " x does not equal y" << endl;
    }
    else
        cout << " x equals y " << endl;

    // short circuit evaluation
    int c = 1;
    int d = 2;

    if (c == 1 && d++ == 2)
    {
        // do something
    }

    cout << d << endl;

    // De Morgan's Law
    !(x || y);
    !x && !y;


    // XOR
    // f f = f
    // f t = t
    // t f = t
    // t t = f
    cout << (x != y) << endl;

    bool v1 = true;
    bool v2 = false;
    bool v3 = false;

    bool r1 = v1 || v2 && v3;
    bool r2 = (v1 || v2) && v3;
    bool r3 = v1 || (v2 && v3); // r1은 이런식으로 계산 됨. &&가 ||보다 우선 순위. 그냥 괄호 처서 하면 실수 위험 없음.
    cout << r1 << endl;
    cout << r2 << endl;

    return 0;
}

