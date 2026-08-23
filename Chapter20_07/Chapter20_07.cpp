// Chapter20_07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <utility> // std::forward

using namespace std;

struct MyStruct
{};

void func(MyStruct& s)
{
	cout << "Pass by L-ref" << endl;
}

void func(MyStruct&& s)
{
	cout << "Pass by R-ref" << endl;
}

/*void func(MyStruct s)
{
	cout << "Pass by Value" << endl;
}*/

template<typename T>
void func_wrapper(T&& t)
{
	func(std::forward<T>(t));
}

int main()
{
    MyStruct s;

	func_wrapper(s);
	func_wrapper(MyStruct());
    //func(s);
    //func(MyStruct());

    
	return 0;
}
