// Chapter5_10.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 구조체 struct

#include <iostream>
#include <string>

using namespace std;

struct Person
{
    double  height = 180;
    float   weight = 65.0;
    int     age =21;
    string  name = "None";

    void print()
    {
        cout << height << " " << weight << " " << age << " " << name;
        cout << endl;
    }
};

/*위에 처럼 그냥 구조체 안에 넣어버릴 수 있음
// .은  Member Access Operator
void printPerson(Person ps)
{
    cout << ps.height << " " << ps.weight << " " << ps.age << " " << ps.name;
    cout << endl;
}
*/

struct Family
{
    Person me, mom, dad;
};

Person getyou()
{
    Person you{ 1.0,50.0,20,"Nom Nom" };

    return you;
}

struct Employee // 2 + 4 + 8 = 14 가 아니라 패딩 되기 때문에 2 + (2) + 4 + 8 = 16
{
    short   id; // 2 byte
    int     age; // 4 byte
    double  wage; // 8 byte
};

int main()
{
    //구조체를 안쓰면
    //double height1, height2, height3;
    //double height[100];
    //int age1, ag2, ...;
   
    /*me.age = 20;
    me.name = "Jack Jack";
    me.weight = 100.0*/

    Person me{ 2.0,100.0,20,"Jack Jack" };
    //Person me2(me); 가능함


    //printPerson(me); 구조체 밖에 있을 때
    me.print();
    
    Person you_from_func = getyou();
    you_from_func.print();

    Employee emp1;
    cout << sizeof(Employee) << endl; // ?!?! 14가 아니라 16이 나옴. // data structure alignment
    return 0;
}

