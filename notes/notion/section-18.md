---
강의 수: 5
상태: 완료
섹션 번호: 18
섹션명: 섹션 18. std::string 문자열 클래스
완료일:
  end: null
  start: 2026-08-22
  time_zone: null
완료한 강의 수: 5
중요도: 기본
진도율: 100
총 시간: 54분
---

# 섹션 18. std::string 문자열 클래스

## 📝 핵심 개념 정리
wstring으로 여러나라말 출력
### std::string의 여러가지 생성자들과 형변환
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

template <typename T>
std::string ToString(T x)
{
    std::ostringstream osstream;
    osstream << x;
    return osstream.str();
}

template <typename T>
bool FromString(const std::string& str, T& x)
{
    std::istringstream isstream(str);
    return (isstream >> x) ? true : false;
}

int main()
{
    //std::string my_string("My string");
    std::string my_string(ToString("My string"));


    std::cout << my_string << std::endl;

    //std::string second_string(my_string, 3, 5);
    std::string second_string(10, 'A');

    std::cout << second_string << std::endl;

    std::vector<char> vec;
    for (auto e : "Today is a good day.")
        vec.push_back(e);

    std::string third_string(vec.begin(),std::find(vec.begin(),vec.end(),'y'));
    std::cout << third_string << std::endl;


    std::string my_str(std::to_string(1004));
    my_str += std::to_string(128);
    std::cout << my_str << std::endl;

    float f = std::stoi(my_str);

    std::cout << my_str << std::endl;
    std::cout << f << std::endl;
    return 0;
}
```
### std::string 길이와 용량
```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    //string my_str("");
    string my_str("0123456789");
    my_str.reserve(1000);

    cout << my_str.length() << endl;

    cout << std::boolalpha;
    cout << my_str.empty() << endl;
    cout << my_str.size() << endl;
    cout << my_str.capacity() << endl;
    cout << my_str.max_size() << endl;

    return 0;
}
```
### 문자 접근하기와 배열로의 변환
```cpp
string my_str("abcdefg");

cout << my_str.c_str() << endl;
const char* arr = my_str.c_str();
cout << arr[6] << endl;
cout << arr[7] << endl;
cout << (int)arr[7] << endl;

try
{
    //my_str[100] = 'X';
    my_str.at(100) = 'X'; // at을 쓰면 오류 처리를 해줌
}
catch (std::exception & e)
{
    cout << e.what() << endl;
}

cout << my_str[0] << endl;
cout << my_str[3] << endl;

my_str[3] = 'Z';
cout << my_str[3] << endl;
cout << my_str << endl;
```
### string 대입,교환,덧붙이기,삽입
```cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1("one");

    string str2;
    str2 = str1;
    str2 = "two";
    str2.assign("two").append(" ").append("three");

    cout << str1 << " " << str2 << endl;

    std::swap(str1, str2);

    cout << str1 << " " << str2 << endl;

    str1.swap(str2);

    cout << str1 << " " << str2 << endl;

    str1.append("three");

    str1 += "three";

    str1 = str2 + "four";

    cout << str1 << endl;

    str1.push_back('A');

    cout << str1 << endl;

    str1.insert(2, "aaaaa");
    cout << str1 << endl;

    return 0;
}
```
## 💻 코드 스니펫
```cpp
// 직접 따라 친 코드 중 기억할 것
```
## 🔥 헷갈린 것들 / 질문
-
## ✅ 복습 체크
- [x] 강의 완주
- [x] 코드 직접 따라 침
- [ ] 복습 1회
