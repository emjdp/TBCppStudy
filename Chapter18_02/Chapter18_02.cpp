// Chapter18_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

template <typename T>
std::string ToString(T x)
{
    std::ostringstream osstream;
    osstream << x;
    return osstream.str();
}

template <typename T>
bool FromString(const std::string& str, T& x)
{
    std::istringstream isstream(str);
    return (isstream >> x) ? true : false;
}

int main()
{
    //std::string my_string("My string");
    std::string my_string(ToString("My string"));


    std::cout << my_string << std::endl;

    //std::string second_string(my_string, 3, 5);
    std::string second_string(10, 'A');

    std::cout << second_string << std::endl;

    std::vector<char> vec;
    for (auto e : "Today is a good day.")
        vec.push_back(e);

    std::string third_string(vec.begin(),std::find(vec.begin(),vec.end(),'y'));
    std::cout << third_string << std::endl;


    std::string my_str(std::to_string(1004));
    my_str += std::to_string(128);
    std::cout << my_str << std::endl;

    float f = std::stoi(my_str);

    std::cout << my_str << std::endl;
    std::cout << f << std::endl;
    return 0;
}

