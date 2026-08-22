---
강의 수: 7
상태: 진행 중
섹션 번호: 19
섹션명: 섹션 19. 입력과 출력
완료일: null
완료한 강의 수: 3
중요도: 기본
진도율: 43
총 시간: 1시간 44분
---

# 섹션 19. 입력과 출력

## 📝 핵심 개념 정리
### istream으로 입력 받기
```cpp
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
```
### ostream으로 출력하기
```cpp
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //cout.setf(std::ios::showpos);

/*    cout.unsetf(std::ios::dec);
    cout.setf(std::ios::hex);*/

    //cout.setf(std::ios::hex, std::ios::basefield);

/*    cout << std::hex << std::uppercase;
    cout << 108 << endl;*/

    cout.unsetf(std::ios::showpos);
    cout << 109 << endl;

    //cout << std::defaultfloat;
    cout << std::scientific;
    //cout << std::showpoint;
    cout << std::setprecision(6) << 12.45672348 << endl;

    cout << -12345 << endl;
    cout << std::setw(10) << -12345 << endl;
    cout << std::setw(10) << std::left << -12345 << endl;
    cout << std::setw(10) << std::right << -12345 << endl;
    cout << std::setw(10) << std::internal << -12345 << endl;

    return 0;
```
### 문자열 스트림
```cpp
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    stringstream os;

    //os << "Hello, World!"; // << : insertion operator, >> : extraction operator
    //os.str("Hello, World!");
    //os << "Hello, World!2" << endl;
    //os.str("Hello, World!\n");

    //cout << os.str() << endl;

    /*string str;
    str = os.str();
    cout << str << endl;*/

/*    os << "12345 67.89";

    string str1;
    string str2;

    os >> str1 >> str2;

    cout << str1 << "|" << str2 << endl;*/

    int i = 12345;
    double d = 67.89;

    os << i << " " << d;

    string str1;
    string str2;

    os >> str1 >> str2;

    cout << str1 << "|" << str2 << endl;

    return 0;
}
```
### 흐름 상태와 입력 유효성 검증
## 💻 코드 스니펫
```cpp
// 직접 따라 친 코드 중 기억할 것
```
## 🔥 헷갈린 것들 / 질문
-
## ✅ 복습 체크
- [ ] 강의 완주
- [ ] 코드 직접 따라 침
- [ ] 복습 1회
