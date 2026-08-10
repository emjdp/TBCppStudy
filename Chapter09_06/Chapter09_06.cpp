// Chapter09_06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Simple
{
private:
    int m_id;

public:
    Simple(const int & id_in)
        : m_id(id_in)
    { 
        cout << "Constructor " << m_id << endl;
    }

    ~Simple()
    {
        cout << "Destructor " << m_id << endl;
    }
};

class InArray
{
private:
    int* m_arr = nullptr;
    int m_lenght = 0;

public:
    InArray(const int lenght_in)
    {
        m_lenght = lenght_in;
        m_arr = new int{ m_lenght };

        cout << "Constructor " << endl;
    }

    ~InArray()
    {
        if(m_arr != nullptr) 
            delete[] m_arr;
    }

    int size() { return m_lenght; }

};

int main()
{
    //Simple s1(0);
    //Simple s2(1);

/*
    Simple* s1 = new Simple(0);
    Simple s2(1);

    delete s1;
*/

    while (true)
    {
        InArray my_int_arr(10000);
    }

    return 0;
}

