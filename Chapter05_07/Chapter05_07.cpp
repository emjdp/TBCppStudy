// Chapter05_07.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 열거형

#include <iostream>
#include <typeinfo>
#include <string>
enum Color // Enumeration 열거
{
    COLOR_BLACK = -2,
    COLOR_RED,
    COLOR_BLUE,
    COLOR_GREEN,
    COLOR_SKYBLUE,
    //BLUE는 겹쳐서 안됨.
};

enum Feeling
{
    HAPPY,
    JOY,
    TIRED,
    BLUE
};

int main()
{
    using namespace std;

    Color my_color = COLOR_BLACK;
    cout << my_color << " " << COLOR_BLACK << endl;
    Color paint = COLOR_BLACK;
    Color house(COLOR_BLUE);
    Color appe{ COLOR_RED };

    int color_id = COLOR_GREEN;
    cout << color_id << endl;

    int in_number;
    cin >> in_number;

    if (in_number == static_cast<Color>(0)) // 열거형은 정수와 비교될 때 자동으로 정수형으로 암시적 형변환 되므로, 사실상 in_number == 0 과 똑같다.
        my_color = static_cast<Color>(0);
   


    /* 권장 안함
    string str_input;

    std::getline(cin, str_input);

    if (str_input == "COLOR_BLACK")
        my_color = static_cast<Color>(0);
    */
    return 0;
}
