// Chapter7_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void printArray(const int array[], const int length)
{
	for (int index = 0; index < length; ++index)
	{
		cout << array[index] << " ";
	}
	cout << endl;
}

int main()
{
	/* 선택 정렬	value	index
	3 5 2 1 4	1		3
	1 5 2 3 4	2		2
	1 2 5 3 4	3		3
	1 2 3 5 4	4		4
	1 2 3 4 5
	*/
	const int length = 5;

	int array[length] = { 5,3,2,1,4 };

	printArray(array, length);

	for (int index = 0; index < length; ++index)
	{
		int temp = index;
		for (int comp = index + 1; comp < length; ++comp)
		{
			if (array[comp] < array[temp]) temp = comp;
		}
		int swapTemp = array[index];
		array[index] = array[temp];
		array[temp] = swapTemp;
		// srd::swap(...) 
	}
	
	printArray(array, length);

	return 0;
}

 