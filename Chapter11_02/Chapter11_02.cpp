// Chapter11_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Monster.h"
using namespace std;

int main()
{
    Monster mon1("Sanson", Position2D(0, 0));

    cout << mon1 << endl;

    {
        mon1.moveTo(Position2D(1, 1));
        cout << mon1 << endl;
    }
}

