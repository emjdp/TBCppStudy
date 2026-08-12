// Chapter10_06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
using namespace std;

class IntList
{
private:
	int m_list[10];
public:
	void setItem(int index, int value)
	{
		m_list[index] = value;
	}

	int getItem(int index)
	{
		return m_list[index];
	}

	int* getList() // array 자체가 포인터라 이렇게도 가능함
	{
		return m_list;
	}
};


class IntList2
{
private:
	int m_list[10];
	//int m_list[10] = { 1,2,3,4,5,6,7,8,9,10 };
public:
	int& operator [] (const int index)
	{
		assert(index >= 0);
		assert(index < 10);

		return m_list[index];
	}

/*	const int& operator [] (const int index) const
	{
		return m_list[index];
	}*/
};

int main()
{
	IntList my_list;
	my_list.setItem(3, 1);
	cout << my_list.getItem(3) << endl;

	my_list.getList()[2] = 5;
	cout << my_list.getList()[2] << endl; 
	// 계속 ()를 붙여야 하니 불편. 첨자 연산자 오버로딩으로 해결

	IntList2 my_list2;
	my_list2[3] = 10;
	cout << my_list2[3] << endl;
	

	//주의
	IntList2* list = new IntList2;

	//list[3] = 10; // not OK
	(*list)[3] = 10; // OK

	return 0;
}

