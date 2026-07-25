// Chapter4_quiz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>

int main()
{
    using namespace std;

    unsigned char option_viewed = 0x01;
    unsigned char option_edited = 0x02;
    unsigned char option_liked = 0x04;
    unsigned char option_shared = 0x08;
    unsigned char option_deleted = 0x80;

    unsigned char my_article_flags = 0;

    cout << bitset<8>(my_article_flags) << endl;

    cout << bitset<8>(option_viewed) << endl;
    cout << bitset<8>(option_edited) << endl;
    cout << bitset<8>(option_liked) << endl;
    cout << bitset<8>(option_shared) << endl;
    cout << bitset<8>(option_deleted) << endl;

    my_article_flags |= option_viewed;
    cout << "viewed!" << bitset<8>(my_article_flags) << endl;

    my_article_flags ^= option_liked;
    cout << "liked!" << bitset<8>(my_article_flags) << endl;

    my_article_flags ^= option_liked;
    cout << "unliked!" << bitset<8>(my_article_flags) << endl;

    if ((my_article_flags & option_viewed) == option_viewed) { my_article_flags |= option_deleted; }
    cout << bitset<8>(my_article_flags) << endl;


    return 0;
}

