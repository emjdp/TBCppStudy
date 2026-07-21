// Chapter3_8.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 리터럴 상수

#include <iostream>

int main()
{
	using namespace std;

	float pi = 3.14f;
	int i = 1234; // 캐스팅 안하고 -1234u나 1234U하는 경우도 있음

	//Decimal : 0 1 2 3 4 5 6 7 8 9 
	//Octal	  : 0 1 2 3 4 5 6 7 
	//Hexa	  : 0 1 2 3 4 5 6 7 8 9 A B C ...

	int x = 012; // 8진수
	cout << x << endl; // 10
	int y = 0xF; // 16진수
	cout << y << endl;
	int z = 0b1010'1010; // 2진수 ' 기호 컴파일러가 무시해줌
	cout << z << endl;

	int num_items = 123;
	// int price = num_items * 10 보다는
	const int price_per_item = 10;
	int price = num_items * price_per_item;

	return 0;
}
