// Chapter13_09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Base
{
public:
    int m_i = 0;

    virtual void print()
    {
        cout << "I'm Base" << endl;
    }
};

class Derived : public Base
{
public:
    int m_j = 1;

    virtual void print() override
    {
        cout << "I'm derived" << endl;
    }
};

void doSomething(Base& b) // & 없으면 복사되버리면서 다형성 사용 불가
{
    b.print();
}


int main()
{
    Derived d;
    //Base& b = d;

    Base b;
    b = d; // 객체 잘림. 다형성 사용 불가

    b.print();

    Base a;
    Derived c;

    cout << endl;

    std::vector<Base*> my_vec;
    my_vec.push_back(&a);
    my_vec.push_back(&c);

    for (auto& ele : my_vec)
        ele->print();

    // 레퍼런스로 구현하고 싶으면

    Base e;
    Derived f;

    std::vector<std::reference_wrapper<Base>> my_vec2;
    my_vec2.push_back(e);
    my_vec2.push_back(f);

    for (auto& ele : my_vec2)
        ele.get().print();

    return 0;
}

