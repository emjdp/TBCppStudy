// Chapter07_05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    const int num_rows = 3;
    const int num_coloums = 5;

    for (int row = 0; row < num_rows; ++row)
    {
        for (int col = 0; col < num_coloums; ++col)
            //cout << '[' << row << ']' << '[' << col << ' ]' << '\t'; //  ' ['는 공백(0x20)과 ](0x5D)라는 두 문자의 아스키 코드가 합쳐진 0x205D 라는 16진수 정수가 됨
            cout << '[' << row << ']' << '[' << col << ']' << '\t';
        cout << endl;

    }
    cout << endl;


    int array[num_rows][num_coloums] = // row-major <-> column-major
    {
        {1,2,3,4,5}, //row 0
        {6,7,8,9,10}, //row 1
        {11,12,13,14,15} //row2
    };


    for (int row = 0; row < num_rows; ++row)
    {
        for (int col = 0; col < num_coloums; ++col)
            //cout << array[row][col] << '\t';
            cout << (int) & array[row][col] << '\t';

        cout << endl;

    }
    return 0;
}

