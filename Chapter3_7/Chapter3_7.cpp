// Chapter3_7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <limits>

int main()
{
    using namespace std;

    char c1(65);
    char c2('A'); // "Hello World" // std::string

    cout << c1 << " " << c2 << " " << int(c1) << " " << int(c2) << endl;

    // c-style casting
    cout << (char)65 << endl;
    cout << (int)'A' << endl;

    // cpp style casting
    cout << char(65) << endl;
    cout << int('A') << endl;

    cout << static_cast<char>(65) << endl;
    cout << static_cast<int>('A') << endl;

    cout << "-----------------" << endl;
    char ch(97);
    cout << ch << endl;
    cout << static_cast<int>(ch) << endl;
    cout << ch << endl;
    cout << "-----------------" << endl;

    cout << int('\n') << endl; // 10
    // \n과 endl의 차이: \n 는 단순히 줄바꿈이지만 endl은 cout 버퍼에 있는 걸 다 출력하고 줄바꿈하라
    // std::flush는 줄바꿈 안하고 버퍼에 있는걸 다 출력하라.
    // \t는 tab. "출력하고 싶으면 \" //   \a 는 소리
    cout << "line change test \nnice";

    // wchar_t l; //리눅스에서 쓴다고 함
    // char16_t char32_t 도 있음

    char c3(65);
    cin >> c3; //abc 이렇게 입력하면 버퍼에 저장되서 순차적으로 됨
    cout << c3 << " " << static_cast<int>(c3) << endl;

    cin >> c3;
    cout << c3 << " " << static_cast<int>(c3) << endl;

    cin >> c3;
    cout << c3 << " " << static_cast<int>(c3) << endl;

 
    return 0;
}

