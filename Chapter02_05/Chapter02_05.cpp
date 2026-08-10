#include <iostream>

using namespace std;

void doSomething(int x) // .....
{
    x = 123;
    cout << x << " inside " << &x << endl;

}


int main()
{

    int x(3);

    cout << x << " " << &x << endl;

    { //지역 범위
        int x = 1;
        //x = 1; // 이건 같은 메모리
        cout << x << " " << &x << endl;

    }
    {
        int x = 2;
        cout << x << " " << &x << endl;

    }
    cout << x << " 1 " << &x << endl;
    doSomething(x);
    cout << x << " 2 " << &x << endl;

    return 0;
}
