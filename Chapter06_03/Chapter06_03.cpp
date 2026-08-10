// Chapter06_03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

enum class Colors
{
    BLACK,
    WHITE,
    RED,
    GREEN,
    BLUE,
};

void printColorName(Colors color)
{
/*    if (color == Colors::BLACK)
        cout << "Black" << endl;
    else if (color == Colors::WHITE)
        cout << "White" << endl;
    else if (color == Colors::RED)
        cout << "Red" << endl;  */
    /*
    switch (color) // Colors::xxx 반복해서 치기 귀찮음
    {
    case Colors::BLACK:
        cout << "Black";
        break;
    }
    */
    switch (static_cast<int>(color))
    {
    case 0:
        cout << "Black";
        break;
    case 1:
        cout << "White";
        break;
    case 2:
        cout << "RED";
        break;
    }
    cout << endl;
    
}

int main()
{
    printColorName(Colors::WHITE);
    int x;
    cin >> x;

    
    switch (x)
    {
        //int b = 5; 선언은 되지만 초기화는 case 안에서만 가능
    case 0:
        cout << "Zero";
        [[fallthrough]];
    case 1:
        cout << "One";
        [[fallthrough]];
    case 2:
        cout << "Two";
        [[fallthrough]];
    case 3:
        cout << "three";
        int b;
        break;
    case 4:
        b = 4;
        cout << "four" << b; //문제 없음 case 3에 넣어둬도 switch 바로 밑에 넣는거랑 같음. 이딴짓은 그냥 안하는게 나음.
        // 내부에서 b를 쓰는거면 switch를 하나의 {}로 감싸로 맨 위에 int b; 해서 처리하는게 좋은 선택. 
        break;
    default:
        cout << "Undefined input " << x << endl;
        break; // 당연히 없어도 됨.
    }
    cout << endl;
    // 0입력시 ZeroOneTwo 1입력시 OneTwo 2입력시 Two ?!?! 실행 이후 그 밑에걸 다 실행해버림
    //break 로 방지 가능. 의도적으로 Fallthrough 할 수도 있고. [[fallthrough]]; 로 속성 추가 가능 c++17부터
    return 0;
}


