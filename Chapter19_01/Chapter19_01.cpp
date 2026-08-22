// Chapter19_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
/*    cout << "Enter a number" << endl;

    int i;
    cin >> i;
    cout << i << endl;*/

    //char buf[5];

    //cin.get(buf, 5);
    //cin.getline(buf, 5);
     
    //cout << cin.gcount() << " " << endl;

    //cin >> setw(5) >> buf;
    //cout << buf << endl;
    
    /*cin >> setw(5) >> buf;
    cout << buf << endl;*/

    /*char ch;
    while (cin >> ch) // 빈칸 포함은 cin.get(ch)
        cout << ch;*/

    /*int i;
    float f;

    cin >> i >> f;
    cout << i << " " << f << endl;*/
    

/*    string buf;

    getline(cin, buf);
    cout << buf.size() << " " << endl;*/

    char buf[1024];

    //cin.ignore(2);

    //cout << (char)cin.peek() << endl;

    cin >> buf;
    cout << buf << endl;

    cin.putback('A');
    //cin.unget();
    
    cin >> buf;
    cout << buf << endl;
    return 0;
}

