// Chapter07_06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char myString[] = "string"; // 문자열 맨 마지막에 null character(\0)가 있어서 7글자

    for (int i = 0; i < 7; ++i)
    {
        cout << (int)myString[i] << endl;
    }
    cout << sizeof(myString) / sizeof(myString)[0] << endl;

    char uString[255];
    //cin >> uString;
    cin.getline(uString, 255);
    //uString[4] = '\0'; // 4번 인덱스 부터 뒤로 생략
    cout << uString << endl;

    int ix = 0;
    while (true)
    {
        if (uString[ix] == '\0') break;

        cout << uString[ix] << " " << (int)myString[ix] << endl;
        ++ix;
    }


    char source[] = "Copy this!";
    char dest[50];
    strcpy_s(dest,50, source);

    cout << source << endl;
    cout << dest << endl;

    strcat_s(dest, source);
    cout << dest << endl;


    //strcmp() 같으면 0 다르면 -1


    return 0;
}

