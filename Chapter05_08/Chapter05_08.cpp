// Chapter05_08.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 영역 제한 열거형 (열거형 클래스)

#include <iostream>

int main()
{
    using namespace std;

    enum Color
    {
        BLACK,
        RED,
        BLUE,
        GREEN,
        SKYBLUE,
    };

    enum Fruit
    {
        BANANA,
        APPLE,
    };

    Color color = RED;
    Fruit fruit = APPLE;

    if (color == fruit) // integer 로 바꿔서 비교 되서 같다고 나옴.
        cout << "Color is fruit ? " << endl;

    enum class Color1
    {
        BLACK,
        RED,
        BLUE,
    };

    enum class Fruit1
    {
        BANANA,
        APPLE,
    };

    Color1 color1 = Color1::RED;
    Fruit1 fruit1 = Fruit1::APPLE; // namespace로 묶어주는거랑 비슷한듯

    // if (color1 == fruit1) // 불가능
    if (static_cast<int>(color1) == static_cast<int>(fruit1)) // 테스트용. 실제로 쓸일은 없음.
        cout << "Color is fruit ? " << endl;

    return 0;
}

