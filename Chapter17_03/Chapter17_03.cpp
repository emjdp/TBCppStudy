// Chapter17_03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main()
{
	using namespace std;

	vector<int> container;
	for (int i = 0; i < 10; ++i)
		container.push_back(i);

	//auto itr = li.begin();
	// list<int>::const_iterator itr;
	auto itr = min_element(container.begin(), container.end());
	cout << *itr << endl;

	itr = max_element(container.begin(), container.end());
	cout << *itr << endl;

	cout << endl;

	itr = find(container.begin(), container.end(), 3);
	container.insert(itr, 128);

	for (auto& e : container) cout << e << " ";
	cout << endl;

	sort(container.begin(), container.end());
	//li.sort();

	for (auto& e : container) cout << e << " ";
	cout << endl;

	reverse(container.begin(), container.end());
	//li.reverse();

	for (auto& e : container) cout << e << " ";
	cout << endl;

	return 0;
}