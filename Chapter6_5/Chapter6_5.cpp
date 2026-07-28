// Chapter6_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    cout << "While-loop test" << endl;

    int count = 0; // while 안에 넣고 싶으면 static int count;
    while (count < 10)
    {
        cout << count << endl;
        ++count;
        if (count == 10) break;
    }

//추천하지는 않지만 goto 버전
tryAgain:
    cout << count << endl;
    ++count;

    if (count < 21) goto tryAgain;

    /*

    */
    
    int outer_count = 1;

    while (outer_count <= 5)
    {
        int inner_count = 1;
        while (inner_count <= outer_count)
        {
            cout << inner_count++ << " ";
        }

        cout << endl;
        ++outer_count;
    }

    return 0;
}
