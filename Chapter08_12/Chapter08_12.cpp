// Chapter08_12.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 재귀적 함수 호출

#include <iostream>
using namespace std;

void countDown(int count)
{
    cout << count << endl;

    if(count > 0)
        countDown(count - 1);
}

int sumTo(int sumto)
{
    if (sumto <= 0)
        return 0;
    else if (sumto <= 1)
        return 1;
    else
        return sumTo(sumto - 1) + sumto;
}

int piBo(int n) // 0 1 1 2 3 5 8 13 
{
    if (n <= 1)
        return n;

    return piBo(n - 1) + piBo(n -2);
}

int main()
{
    //countDown(5);
    //cout << sumTo(10) << endl;
    cout << piBo(5) << endl;
    return 0;
}


