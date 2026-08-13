// Chapter11_03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Lecture.h"

int main()
{
    using namespace std;

    // Composition Relationship
    Lecture lec1("Introduction to Computer Programming");
    lec1.assignTeacher(Teacher("Prof. Hong"));
    lec1.registerStudent(Student("Jack Jack", 0));
    lec1.registerStudent(Student("Dash", 1));
    lec1.registerStudent(Student("Violet", 2));

    Lecture lec2("Computational Thinking");
    lec2.assignTeacher(Teacher("Prof. Good"));
    lec2.registerStudent(Student("Jack Jack", 0));

    //TODO: implement Aggregation Relationship

    // test
    {
        cout << lec1 << endl;
        cout << lec2 << endl;

        // event
        lec2.study();

        cout << lec1 << endl;
        cout << lec2 << endl;
    }
}
