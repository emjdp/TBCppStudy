// Chapter16_03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Timer.h"
#include "AutoPtr.h"
#include "Resource.h"

AutoPtr<Resource> generateResource()
{
    AutoPtr<Resource> res(new Resource(10000000));

    return res;
}

int main()
{
    using namespace std;
    streambuf* orig_buf = cout.rdbuf();
    //cout.rdbuf(NULL); // disconnect cout from buffer

    Timer timer;

    {
        AutoPtr<Resource> main_res;
        main_res = generateResource();
    }

    cout.rdbuf(orig_buf);
    cout << timer.elapsed() << endl;

    return 0;
}

