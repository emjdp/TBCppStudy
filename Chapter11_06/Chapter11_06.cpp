// Chapter11_06.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 컨테이너 클래스 구현해보기 / 자력으로

#include <iostream>
#include <initializer_list>
using namespace std;

class intArray
{
private:
    int m_length;
    int* m_data;

public:
    // Constructos
    intArray()
        : m_length(0), m_data(nullptr)
    {}

    intArray(const int length)
        : m_length(length),
        m_data(new int[length]{})
    {}

    intArray(const std::initializer_list<int>& list)
        : intArray()
    {
        initialize(static_cast<int>(list.size()));
        int index = 0;

        for (const int value : list)
        {
            m_data[index] = value;
            ++index;
        }
    }

    // Destructors
    ~intArray() { delete[] m_data; }

    // reset
    void reset()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    // initialize()
    void initialize(const int length)
    {
        reset();

        if (length <= 0)
            return;

        m_data = new int[length] {};
        m_length = length;
    }

    // insertBefore
    void insertBefore(const int& value, const int& ix)
    {
        if (ix <0 || ix > m_length)
            return;

        int* new_data = new int[m_length + 1] {};
        for (int i = 0; i < ix; ++i) { new_data[i] = m_data[i]; }
        new_data[ix] = value;
        for (int i = ix; i < m_length; ++i ) { new_data[i + 1] = m_data[i]; }

        delete[] m_data;
        m_data = new_data;
        m_length += 1;
    }
    
    // remove(const int & ix);
    void remove(const int& ix)
    {
        if (ix <0 || ix >= m_length)
            return;

        if (m_length == 1)
        {
            reset();
            return;
        }

        int* new_data = new int[m_length - 1] {};
        for (int i = 0; i < ix; ++i) { new_data[i] = m_data[i]; }
        for (int i = ix + 1; i < m_length; ++i) { new_data[i - 1] = m_data[i]; }

        delete[] m_data;
        m_data = new_data;
        m_length -= 1;
    }

    //push_back
    void push_back(const int& value)
    {
        insertBefore(value, m_length);
    }

    //print
    void print() const
    {
        for (int i = 0; i < m_length; ++i)
        {
            cout << m_data[i] << ' ';
        }

        cout << '\n';
    }

};
int main()
{
    intArray my_arr{ 1, 3, 5, 7, 9 };
    my_arr.print();
    
    my_arr.insertBefore(10,1); // 1, 10 ,3, 5 ,7 ,9
    my_arr.print();
    
    my_arr.remove(3); // 1, 10, 3, 7, 9
    my_arr.print();

    my_arr.push_back(13); // 1, 10, 3, 7, 9, 13
    my_arr.print();

    return 0;
}

