// Chapter15_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void last()
{
    cout << "last " << endl;
    cout << "Throws exception" << endl;

    throw -1;

    cout << "End last " << endl;
}

void third()
{
    cout << "Third" << endl;

    last();

    cout << "End third" << endl;
}

void second()
{
    cout << "Second" << endl;

    try
    {
        third();
    }
    catch (double)
    {
        cerr << "Second caught double exception" << endl;
    }

    cout << "End second " << endl;
}

void first()
{
    cout << "first" << endl;

    try
    {
        second();
    }
    catch (int)
    {
        cerr << "first caught int exception" << endl;
    }

    cout << "End first " << endl;
}
int main()
{
    cout << "Start" << endl;

    try
    {
        first();
    }
    catch (int)
    {
        cerr << "main caught int exception" << endl;
    }
    
    //uncaught exceptions
    catch (...)
    {
        cerr << "main caught ellipses exception" << endl;
    }


    cout << "End main" << endl;

    return 0;
}

