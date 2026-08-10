#include <iostream> // cout, cin, emdl, ...
#include <cstdio>

int main()
{
    int x = 1024;
    double pi = 3.141592;
    //std::cout << "I love this lecture!" << std::endl;
    std::cout << "I love this lecture!\n\n\n\n\n"; // << std::endl; \n은 new line
    std::cout << "x is " << x << "pi is " << pi << std::endl;

    std::cout << "abc" << "\t" << "def" << std::endl;
    std::cout << "ab" << "\t" << "cdef" << std::endl;

    using namespace std;
    int z = 32;
    cout << z << endl;
    cout << "abc" << "\t" << "def" << endl;
    cout << "ab" << "\t" << "cdef" << endl;
    cout << "\a"; // 오디오 출력

    int s = 1;

    cout << "Before s was " << s << endl;
    cin >> s;
    cout << "Your input is " << s << endl;

    return 0;
}
