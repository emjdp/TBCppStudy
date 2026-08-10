// Chapter05_09.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 자료형에게 가명 붙여주기

#include <iostream>
#include <vector>
#include <cstdint>
int main()
{
    using namespace std;

    typedef vector<pair<string, int> > pairlist_t;
    //using pairlist_t = vector<pair<string, int> >; 이것도 가능.
    //vector<pair<string, int> > pairlist1;
    //vector<pair<string, int> > pairlist2;
    pairlist_t pairlist1;

    typedef double distance_t;

    std::int8_t i(97); // 고정너비정수도 비슷한 거
    
    double      mydistance;
    distance_t  home2work;
    distance_t  home2school;


    return 0;
}

