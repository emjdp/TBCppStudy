#include <iostream>

int main()
{
	int x = 5; // initialization // int x(5); 이것도 됨
	x = 123; //assignment x가 엘벨류 123이 얼벨류
	// x = x + 2 여기서 오른쪽에 있는 x는 변수가 아니라 값이 임시로 복사되는 거

	std::cout << x << std::endl;
	std::cout << &x << std::endl;

	std::cout << "여기부터 실습" << std::endl;

	int y = x;
	std::cout << y << std::endl;
	std::cout << x + y << std::endl; // (x+y)는 l-value 인가 아님 r-value 인가


	return 0;
}