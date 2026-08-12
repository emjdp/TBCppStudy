// Chapter10_11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
using namespace std;

class MyString
{
//private: 
public: // 주소 찍어야 해서 임시로
    char* m_data = nullptr;
    int m_length = 0;

public:
    MyString(const char* source = "")
    {
        assert(source);

        m_length = std::strlen(source) + 1;
        m_data = new char[m_length];

        for (int i = 0; i < m_length; i++)
            m_data[i] = source[i];

        m_data[m_length - 1] = '\0';
    }

    MyString(const MyString& source)  // 깊은 복사
    {
        cout << "Copy constructor " << endl;

        m_length = source.m_length;

        if (source.m_data != nullptr)
        {
            m_data = new char[m_length];

            for (int i = 0; i < m_length; i++)
                m_data[i] = source.m_data[i];
        }
        else
            m_data = nullptr;
    }

    MyString& operator = (const MyString& source)
    {
        cout << "Assignment operator " << endl;

        if (this == &source) // prevent self-assignment
            return *this;

        delete[] m_data;

        m_length = source.m_length;

        if (source.m_data != nullptr)
        {
            m_data = new char[m_length];

            for (int i = 0; i < m_length; i++)
                m_data[i] = source.m_data[i];
        }
        else
            m_data = nullptr;

        return *this;
    }

    ~MyString()
    {
        delete[] m_data;
    }

    char* getString() { return m_data; }
    int getLength() { return m_length; }
};

int main()
{
    MyString hello("Hello");

    cout << (int*)hello.m_data << endl;
    cout << hello.getString() << endl;

    {
        MyString copy = hello; // 같은 메모리 가리킴. 포인터 주소만 복사하는 '얕은 복사'
        cout << (int*)copy.m_data << endl; // hello.m_data랑 같음
        cout << copy.getString() << endl;
    }

    cout << hello.getString() << endl; // 메모리 해제되서 댕글링 포인터가 됨.

    cout << endl;

    MyString str1 = hello; // Copy constructor // MyString str1(hello);로 써두면 덜 헷갈릴지도

    MyString str2; 
    str2 = hello; // Assignment operator

    return 0;
}


