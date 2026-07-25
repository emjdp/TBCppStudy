#include <iostream>

#include "MyConstants.h"
extern int a = 1;

void doSomething2()
{
	using namespace std;

	cout << "In test.cpp file " << Constants::pi << " " << &Constants::pi << endl;
}