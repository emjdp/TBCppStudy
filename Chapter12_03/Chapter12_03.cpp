// Chapter12_03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Mother
{
public:
//private:
    int m_i;

public:
    Mother()
        : m_i(1)
    {
        cout << "Mother construction" << endl;
    }
};

class Child : public Mother
{
private:
    double m_d;

public:
    Child()
        :m_d(1.0)
    {
        cout << "Child construction" << endl;
    }
};

int main()
{
    Child c1; // Mother 생성자 후 Child 생성자. // 사실상 

    return 0;
}

