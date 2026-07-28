// Chapter6_10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int getInt()
{
    while (true)
    {
        cout << "Enter a integer number : ";
        int x;
        cin >> x;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            cout << "Invalid numberm please try agian" << endl;
        }
        else
        {
            std::cin.ignore(32767, '\n');
            return x;
        }
    }
    
}


int getOperator()
{
    while (true)
    {
        cout << "Enter an operator (+, -) : ";
        char op;
        cin >> op;
        std::cin.ignore(32767, '\n');

        if (op == '+' || op == '-')
            return op;
        else
            cout << " Invalid operator, please try again" << endl;
    }

}

void printResilt(int x, char op, int y)
{
    if (op == '+') cout << x + y << endl;
    else if (op == '-') cout << x - y << endl;
    else
    {
        cout << "Invalid opeartor" << endl;
    }
}

int main()
{
    int x = getInt();
    char op = getOperator();
    int y = getInt();

    printResilt(x, op, y);

    return 0;

}

