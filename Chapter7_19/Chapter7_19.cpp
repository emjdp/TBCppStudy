// Chapter7_19.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 다중 포인터와 동적 다차원 배열

#include <iostream>

using namespace std;

int main()
{
    int *ptr = nullptr;
    int **ptrptr = nullptr;

    int value = 5;

    ptr = &value;
    ptrptr = &ptr;

    cout << ptr << " " << *ptr << " " << &ptr << endl;
    cout << ptrptr << " " << *ptrptr << " " << &ptrptr << endl;
    cout << **ptrptr << endl;

    const int row = 3;
    const int col = 5;

    const int s2da[row][col] =
    {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15}
    };

    int *r1 = new int[col] {1, 2, 3, 4, 5};
    int *r2 = new int[col] {6, 7, 8, 9, 10};
    int *r3 = new int[col] {11, 12, 13, 14, 15};

    int **rows = new int* [row] {r1, r2, r3};

    for (int r = 0; r < row; ++r)
    {
        for (int c = 0; c < col; c++)
            cout << rows[r][c] << " ";
        cout << endl;
    }

    return 0;
}

