// Chapter16_04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <utility> //std::move
#include "AutoPtr.h"
#include "Resource.h"
#include <vector>

using namespace std;

template<class T>
void MySwap(T& a, T& b)
{
    //T tmp = a;
    //a = b;
    //b = tmp;

    T tmp{ std::move(a) };
    a = std::move(b);
    b = std::move(tmp);
}

int main()
/*{


    AutoPtr<Resource> res1(new Resource(10000000));

    cout << res1.m_ptr << endl;

    AutoPtr< Resource> res2 = std::move(res1); // std::move R-value로 리턴

    cout << res1.m_ptr << endl;
    cout << res2.m_ptr << endl;
}*/

/*{
    AutoPtr<Resource> res1(new Resource(3));
    res1->setAll(3);

    AutoPtr<Resource> res2(new Resource(5));
    res2->setAll(5);

    res1->print();
    res2->print();

    MySwap(res1, res2);

    res1->print();
    res2->print();

}*/

{
    vector<string> v;
    string str = "Hello";

    v.push_back(str); // L-value 로

    cout << str << endl; // Hello
    cout << v[0] << endl; // Hello

    v.push_back(std::move(str)); // R-value 로

    cout << str << endl; // 출력 없음
    cout << v[0] << " " << v[1] << endl; // Hello Hello 이동해옴
}