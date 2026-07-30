// Chapter7_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    const int num_students = 5;
    int scores[num_students] = { 84,92,76,81 };

    int total_score = 0;
    int max_score = 0;

    for (int i = 0; i < num_students; ++i)
    {
        total_score += scores[i];
        //if (max_score < scores[i]) max_score = scores[i];
        max_score = (max_score < scores[i]) ? scores[i] : max_score;
    }

    cout << total_score << endl;
    cout << max_score << endl;

    return 0;
}

