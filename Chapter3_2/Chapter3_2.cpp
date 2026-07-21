// Chapter3_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 정수형

#include <iostream>
#include <cmath>
#include <limits>

int main()
{
	using namespace std;

	short	s = 1; // 2 bytes = 2* 8 bits = 16 bits
	short	d = 1;
	int		i = 1;
	long l = 1;
	long long ll = 1;
	unsigned int j = -1; // 알아서 바꿔줌. overflow 됨
	
	cout << j << endl; // 4294967295

	cout << std::pow(2, sizeof(short) * 8 - 1) - 1 << endl; // short가 표현 할 수 있는 가짓 수 / 부호 자리 제외/ 0 제외
	cout << std::numeric_limits<short>::max() << endl; // 32767
	cout << std::numeric_limits<short>::min() << endl; // -32768
	cout << std::numeric_limits<short>::lowest() << endl; // -32768

	cout << std::numeric_limits<long>::max() << endl; // 2147483647
	cout << std::numeric_limits<long>::min() << endl; // -2147483648
	cout << std::numeric_limits<long>::lowest() << endl; // -2147483648

	cout << std::numeric_limits<long long>::max() << endl; // 9223372036854775807
	cout << std::numeric_limits<int>::max() << endl; // 2147483647
	cout << std::numeric_limits<unsigned int>::max() << endl; // 4294967295 부호 자리 할당 안 해서 더 많음


	s = 32767;
	s = s + 1; // 32768?

	cout << "32768? " << s << endl; // -32768이 나옴 overflow

	d = std::numeric_limits<short>::min();
	d = d - 1; // -32769? 
	cout << "-32769? " << d << endl; // 32767이 나옴 overflow


	cout << sizeof(short) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(long) << endl;
	cout << sizeof(long long) << endl;


	int n = 22 / 4;
	cout << n << endl;
	cout << 22 / 4 << endl; // 정수끼리의 연산은 정수로
	cout << (float)22 / 4 << endl; // 22를 float로 바꿈. 둘중 하나를 float로 바꾸면 float로 나옴.

	return 0;
}
