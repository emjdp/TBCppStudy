// Chapter09_03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(const int& num_in, const int& den_in = 1)
    {
        m_numerator = num_in;
        m_denominator = den_in;

        cout << "Fraction constructor" << endl;
    }

    void print()
    {
        cout << m_numerator << " / " << m_denominator << endl;
    }
};
int main()
{
    /*Fraction frac; // 파라미터가 하나도 없는 생성자 일 때 이럴게
    frac.print();*/
    Fraction one_thirds(1, 3); // { } 로 하면 형변환 자동으로 안됨
    one_thirds.print();

    return 0;
}

