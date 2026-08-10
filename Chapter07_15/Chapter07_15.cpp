// Chapter07_15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void doSomething(const int &x)
{
    cout << x << endl;
}

int main()
{
    const int x = 5;
    const int &ref_x = 5; // const 레퍼런스는 리터럴로 초기화 가능. 주소도 나옴
    //const int& ref_x = 2 + 3; 

    const int& ref_2 = ref_x;

    cout << ref_x << " " << &ref_x << endl;

    // 응용 : 레퍼런스로 함수에 넣는데 리터럴을 바로 넣을 수 있음
    int a = 1;
    doSomething(a);

    doSomething(1);
    doSomething(3 * 4);
    doSomething(a + 4);

    return 0;
}

