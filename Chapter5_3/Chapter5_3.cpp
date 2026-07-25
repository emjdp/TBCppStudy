// Chapter5_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

namespace a
{
    int my_var(10);
    int my_a(123);
}

namespace b
{
    int my_var(20);
    int my_b(456);
}

int main()
{
    using namespace std;
    /*using std::cout;
    using std::endl;*/

    
    {
        using namespace a;
        cout << my_var << endl;
    }
    
    using namespace b;
    cout << "Hello " << endl;
    //cout << my_var << endl; // {}로 안 묶어주면 "my_var" is ambiguous
    cout << my_var << endl;


    return 0;
}

