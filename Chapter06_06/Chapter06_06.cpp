// Chapter06_06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    int selection;

    do
    {
        cout << "1. add"    << endl;
        cout << "2. sub"    << endl;
        cout << "3. mult"   << endl;
        cout << "4. div"    << endl;
        cin >> selection;
    } while (selection <= 0 || selection >= 5);

    cout << "You selected " << selection << endl;

    return 0;
}

