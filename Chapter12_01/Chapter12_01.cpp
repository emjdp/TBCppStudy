// Chapter12_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Mother
{
private:
//protected: // 자식은 접근 가능
    int m_i;

public:
    Mother()
        : m_i(0)
    { }

    Mother(const int& i_in)
        : m_i(i_in)
    {
        std::cout << "Mother constructor" << std::endl;
    }

    void setValue(const int& i_in)
    {
        m_i = i_in;
    }

    int getValue()
    {
        return m_i;
    }
};

class Child : public Mother // derivde class
{
private:
    double m_d;

public:
    Child(const int& i_in, const double& d_in)
    //    : m_i(i_in), m_d(d_in)
        : Mother(i_in), m_d(d_in)
    {}

    void setValue(const int & i_in, const double & d_in)
    {
        Mother::setValue(i_in);
        m_d = d_in;
        //m_i = i_in;
    }

    void setValue(const double& d_in)
    {
        m_d = d_in;
    }

    double getValue()
    {
        return m_d;
    }
};

int main()
{
    Mother mother(1024);
    mother.setValue(1024);
    cout << mother.getValue() << endl;

    Child child(1024, 128);
    child.Mother::setValue(1024);
    child.setValue(128);
    cout << child.getValue() << endl;

    return 0;
}

