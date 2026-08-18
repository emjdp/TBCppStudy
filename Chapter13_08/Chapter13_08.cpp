// Chapter13_08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class PowerdDevice
{
public:
    int m_i;

    PowerdDevice(int power)
    {
        cout << "PowerdDevice: " << power << '\n';
    }
};

class Scanner : virtual public PowerdDevice
{
public:
    Scanner(int scanner, int power)
        : PowerdDevice(power)
    {
        cout << "Scanner: " << scanner << '\n';
    }
};

class Printer : virtual public PowerdDevice
{
public:
    Printer(int printer, int power)
        : PowerdDevice(power)
    {
        cout << "Printer: " << printer << '\n';
    }
};

class Copier : public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power)
        : Scanner(scanner, power), Printer(printer, power),
        PowerdDevice(power)
    {
    }
};

int main()
{
    Copier cop(1, 2, 3);

    cout << &cop.Scanner::PowerdDevice::m_i << endl;
    cout << &cop.Printer::PowerdDevice::m_i << endl;

    return 0;
}