// Chapter9_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Friend
{
public: // access specifier (public, private, protected)
    string name;
    string address;
    int age;
    double height;
    double weight;

    void print()
    {
        cout << name << " " << address << " " << age << " " << height << " " << weight << endl;
    }
};

/*
void print(const string& name, const string& address, const int& age, const double& height, const double& weight)
{
    cout << name << " " << address << " " << age << " " << height << " " << weight << endl;
}

void print(const Friend &fr)
{
    cout << fr.name << " " << fr.address << " " << fr.age << " " << fr.height << " " << fr.weight << endl;
}
*/

int main()
{

    Friend jj("Jack Jack", "Uptown", 2,30, 10); // instanciation, instance
    /*
    print(jj.name, jj.address, jj.age, jj.height, jj.weight);
    print(jj);
    */

    jj.print();

    vector<Friend> my_friends;
    my_friends.resize(2);

    //my_friends[0].print();
    //my_friends[1].print();
    for (auto& ele : my_friends)
        ele.print();

    return 0;
}

