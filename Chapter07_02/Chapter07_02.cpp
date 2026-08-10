// Chapter07_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
// array 

#include <iostream>

using namespace std;

void doSomething(int student_scores[20]) // int student_scores[20] 이건 문법상 포인터. 배열이 아님
{
    cout << &student_scores << endl; // 포인터 변수의 주소가 나옴. 넘겨 받은 배열의 첫번째 주소값을 저장해둔 곳
    cout << &student_scores[0] << endl; // 이건 동일하게 나옴.
    cout << student_scores[0] << endl;
    cout << student_scores[1] << endl;
    cout << student_scores[2] << endl;
    cout << "Size in dosomething " << sizeof(student_scores) << endl;
}
int main()
{
    const int num_students = 20;
    int student_scores[num_students] = {1, 2, 3, 4, 5, };

    cout << student_scores << endl; // 배열(식별자,인식자) 이름 자체가 주소로 사용되기 때문에 & 안붙여도 동일
    cout << student_scores[0] << endl;
    cout << student_scores[1] << endl;
    cout << student_scores[2] << endl;
    cout << "Size in main " << sizeof(student_scores) << endl;


    doSomething(student_scores); // 배열의 모든 원소를 통째로 가져오는게 아니라 첫번째 주소값만 복사


    return 0;
}