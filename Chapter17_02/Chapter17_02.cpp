// Chapter17_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

int main()
{
	vector<int> container;
	for (int i = 0; i < 10; ++i)
		container.push_back(i);

	vector<int>::const_iterator itr;
	itr = container.begin();
	while (itr != container.end())
	{
		cout << *itr << " ";

		++itr;
	}
	cout << endl;

	for (auto itr = container.begin(); itr != container.end(); ++itr)
		cout << *itr << " ";

	return 0;
}