// Chapter9_9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Something
{
public:
    int m_value = 0;

    Something(const Something& st_in)
    {
        m_value = st_in.m_value;

        cout << "Copy constructor" << endl;
    }

    Something()
    {
        cout << "Constructor" << endl;
    }

    void setValue(int value) { m_value = value; }
    int getValue() const
    { 
        return m_value; 
    }
};

void print(Something st)
{
    cout << &st << endl;
    cout << st.getValue() << endl;
}

void cprint(const Something &st)
{
    cout << &st << endl;
    cout << st.getValue() << endl;
}

class Myfun
{
public:
    string m_value = "default";

    const string& getValue() const 
    { 
        cout << "const version" << endl;
        return m_value; 
    }

    string& getValue() 
    { 
        cout << "non-const version" << endl;
        return m_value; 
    }
};

int main()
{
    //const Something something;
    //something.setValue(3); // const라서 불가능
    //cout << something.getValue() << endl; // const 맴버 func이 아니라서 사용 불가

    Something some;

    cout << &some << endl;

    print(some);
    cprint(some); // const reference로 복사 안하고 사용


    // 오버로딩 가능
    Myfun mf;
    mf.getValue() = 10;

    const Myfun mf2;
    mf2.getValue();
    
    return 0;
}

