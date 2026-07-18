#include <iostream>

using namespace std;

void printHelloWorld()
{
    cout << "Hello World" << endl;
    return;
    cout << "Hello World2" << endl; // 출력안됨
}

int multiplyTwoNumbers(int num_a, int num_b)
{
    int sum = num_a + num_b;

    return sum;
}

int main()
{
    printHelloWorld();
    cout << 1 + 2 << endl;
    cout << multiplyTwoNumbers(8,13) << endl;
    cout << multiplyTwoNumbers(5, 64) << endl;

    return 0;
}
