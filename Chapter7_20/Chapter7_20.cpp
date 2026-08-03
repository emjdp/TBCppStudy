// Chapter7_20.cpp : This file contains the 'main' function. Program execution begins and ends there.
// std::array

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

void printLength(array<int, 5> my_arr) // 이러면 복사해서 하는거라 &my_arr로 하면 효율적으로 가능.
{
	cout << my_arr.size() << endl;
}

int main()
{
   // int array[5] = {1,2,3,4,5}
	array<int, 5> my_arr = { 1,21,3,40,5 };
	//my_arr = { 0,1,2,3,4 };
	//my_arr = { 0,1,2, };

	//cout << my_arr[10] << endl; 
	//cout << my_arr.at(10) << endl; // 미리 해보고 문제 생기면 예외처리.

	cout << my_arr.size() << endl;
	printLength(my_arr);

	for (auto& element : my_arr)
		cout << element << " ";
	cout << endl;

	std::sort(my_arr.begin(), my_arr.end());

	for (auto& element : my_arr)
		cout << element << " ";
	cout << endl;

	std::sort(my_arr.rbegin(), my_arr.rend());

	for (auto& element : my_arr)
		cout << element << " ";
	cout << endl;


	return 0;
}
