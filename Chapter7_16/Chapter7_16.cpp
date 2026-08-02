// Chapter7_16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Person
{
    int age;
    double weight;
};

int main()
{
    Person person;

    person.age = 5;
    person.weight = 30;

    Person &ref = person;
    ref.age = 15;

    Person *ptr = &person;
    ptr->age = 30;
    //(*ptr).age = 20; // 가능은 하나 잘 안씀

    Person& ref2 = *ptr;
    ref2.age = 45;

    std::cout << &person << std::endl;
    std::cout << &ref2 << std::endl;

    return 0;
}
