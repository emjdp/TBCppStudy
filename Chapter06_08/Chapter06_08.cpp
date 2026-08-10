// Chapter06_08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void breakOrReturn()
{
    while (true)
    {
        char ch;
        cin >> ch;

        if (ch == 'b')
            break;

        if (ch == 'r')
            return; // 함수를 나가 버림
    }
    cout << "Hello" << endl;
}
int main()
{
    int count = 0;

    for (int i = 0; i < 10; ++i)
    {
        if (i % 2 == 0) continue;
        cout << i << endl;
    }

    do
    {
        if (count == 5)
            continue;

        cout << count << endl;
        //count++; // 컨티뉴 하느라 실행안됨
    } //while (count < 10);
    while (++count < 10);

    int c(0);

    bool escape_flag = false;
    char ch;
    while (!escape_flag)
    {
        cin >> ch;
        cout << ch << " " << c++ << endl;
        if (ch == 'x')
            escape_flag = true;
    }

    return 0;
}

