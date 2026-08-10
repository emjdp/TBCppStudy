// Chapter07_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int width;
};

enum StudentName
{
    JACKJACK,   // 0
    DASH,       //1
    VIOLET,     //2
    SEAN,       //3
    SAM,        //4
    NUM_STUDENT,//5
};
int main()
{
    /*
    int num_students = 0;
    cin >> num_students;

    // int students_scores[num_students]; // 런타임에서 사이즈가 고정된 곳에는 array를 사용할 수 없다
    // 하고 싶으면 일단 cin 안하고 const int num_student = 5; 이런식으로 가능
    */
    int one_studemt_score;
    int student_scores[NUM_STUDENT];

    cout << sizeof(one_studemt_score) << endl; // 4
    cout << sizeof(student_scores) << endl; // 20

    one_studemt_score = 100;
    student_scores[0] = 100; // 1st element
    student_scores[1] = 80; // 2nd element
    student_scores[2] = 90;
    student_scores[3] = 50;
    student_scores[4] = 0;
    // student_scores[5] = 0;

    cout << sizeof(Rectangle) << endl;

    Rectangle rect_arr[10];

    cout << sizeof(rect_arr) << endl;

    rect_arr[0].length = 1;
    rect_arr[0].width = 2;

    //int my_array[5] = { 1,2,3,4,5 };
    //int my_array[] = { 1,2,3,4,5 };
    int my_array[]{ 1,2,3,4,5 };
    
    cout << my_array[2] << endl;

    return 0;
}

