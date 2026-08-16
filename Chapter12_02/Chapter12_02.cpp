// Chapter12_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Student.h"
#include "Teacher.h"

int main()
{
    Student std("Jakk Jack");
    std.setName("Jack Jack 2");
    std::cout << std.getName() << std::endl;

    Teacher teacher1("Dr. H");
    std::cout << teacher1.getName() << std::endl;

    std::cout << std << std::endl;
    std::cout << teacher1 << std::endl;

    std.doNothing();
    teacher1.doNothing();

    return 0;
}

