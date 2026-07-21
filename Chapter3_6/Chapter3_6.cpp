// Chapter3_6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool isEqual(int a, int b)
{
    bool result = (a == b);

    return result;
}


int main()
{
    using namespace std;

    cout << std::boolalpha;
    cout << isEqual(1, 1) << endl;
    cout << isEqual(0, 3) << endl;


    bool b1 = true; // copy initialization
    bool b2(false); // direct initialization
    bool b3{ true }; // uniform initialization
    b3 = false;

    cout << b3 << endl;
    cout << b1 << endl;

    //cout << std::noboolalpha;
    //cout << !true << endl; // not operator
    //cout << !false << endl;
    //cout << (true && true) << endl;
    //cout << (true && false) << endl;
    //cout << (false && true) << endl;
    //cout << (false && false) << endl;

    //cout << (true || true) << endl;
    //cout << (true || false) << endl;
    //cout << (false || true) << endl;
    //cout << (false || false) << endl;

    if (false)
    {
        cout << "This is true " << endl;
        cout << "True second line " << endl;
    }     
    else
        cout << "This is false" << endl;

    int n = 0;

    cin >> n;
    if (n % 2 == 0)
        cout << "This is even" << endl;
    else
        cout << "This is odd" << endl;


    return 0;

}