---
강의 수: 7
상태: 완료
섹션 번호: 19
섹션명: 섹션 19. 입력과 출력
완료일:
  end: null
  start: 2026-08-23
  time_zone: null
완료한 강의 수: 7
중요도: 기본
진도율: 100
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
```cpp
#include <iostream>
#include <cctype>
#include <string>
#include <bitset>

using namespace std;

void printCharacterClassification(const int & i)
{
    cout << boolalpha;
    cout << "isalnum " << bool(std::isalnum(i)) << endl;
    cout << "isblank " << bool(std::isblank(i)) << endl;
    cout << "isdigit " << bool(std::isdigit(i)) << endl;
    cout << "islower " << bool(std::islower(i)) << endl;
    cout << "isupper " << bool(std::isupper(i)) << endl;
}

void printStates(const std::ios& stream)
{
    cout << boolalpha;
    cout << "good()=" << stream.good() << endl;
    cout << "eof()=" << stream.eof() << endl;
    cout << "fail()=" << stream.fail() << endl;
    cout << "bad()=" << stream.bad() << endl;
}

bool isAllDigit(const string & str)
{
    bool ok = true;

    for (auto e : str)
        if (!isdigit(e))
        {
            ok = false;
            break;
        }

    return ok;
}

int main()
{
    while (true)
    {
        int i;
        cin >> i;

        printStates(cin);

        cout << i << endl;

        // cout << boolalpha;
        // cout << std::bitset<8>(cin.rdstate()) << endl;
        // cout << std::bitset<8>(std::istream::goodbit) << endl;
        // cout << std::bitset<8>(std::istream::failbit) << endl;
        // cout << !bool((cin.rdstate() & std::istream::failbit) != 0) << endl;

        printCharacterClassification(i);

        cin.clear();
        cin.ignore(1024, '\n');
        cout << endl;
    }

/*    cout << boolalpha;
    cout << isAllDigit("1234") << endl;
    cout << isAllDigit("a1234") << endl;*/
    return 0;
}
```
### 정규 표현식 소개
```cpp
#include <iostream>
#include <regex>

using namespace std;

int main()
{
    ///regex re("\\d+");
    regex re("[ab]");
    //regex re("[[:digit:]]{3}");
    //regex re("[A-Z]+");
    //regex re("[A-Z]{3}");
    //regex re("([0-9]{1})([-]?)([0-9]{1,4})");

    string str;

    while (true)
    {
        getline(cin, str);

        if (std::regex_match(str, re))
            cout << "Match" << endl;
        else
            cout << "No match" << endl;

        // print matches
        {
            auto begin = std::sregex_iterator(str.begin(), str.end(), re);
            auto end = std::sregex_iterator();
            for (auto itr = begin; itr != end; ++itr)
            {
                std::smatch match = *itr;
                cout << match.str() << " ";
            }
            cout << endl;
        }

        cout << endl;
    }

    return 0;
}
```
규칙을 가진 문자열 패턴 정리해서 일치하는지 확인.
### 기본적인 파일 입출력
```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // exit()
#include <sstream>

using namespace std;

int main()
{
    // writing
    if (true)
    {
        ofstream ofs("my_first_file.dat", ios::app);// ios::app, ios::binary
        //ofs.open("my_first_file.dat");

        if (!ofs)
        {
            cerr << "Couldn't open file " << endl;
            exit(1);
        }

        ofs << "Line 1" << endl;
        ofs << "Line 2" << endl;

        /*const unsigned num_data = 10;
        ofs.write((char*)&num_data, sizeof(num_data));

        for (int i = 0; i < num_data; ++i)
            ofs.write((char*)&i, sizeof(i));*/

        /*stringstream ss;
        ss << "Line 1" << endl;
        ss << "Line 2" << endl;
        string str = ss.str();

        unsigned str_length = str.size();
        ofs.write((char*)&str_length, sizeof(str_length));
        ofs.write(str.c_str(), str_length);*/

        //ofs.close(); // not necessary
    }

    // reading
    if (true)
    {
        ifstream ifs("my_first_file.dat");

        if (!ifs)
        {
            cerr << "Cannot open file" << endl;
            exit(1);
        }

        while (ifs)
        {
            std::string str;
            getline(ifs, str);

            std::cout << str << endl;
        }

        /*unsigned num_data;
        ifs.read((char*)&num_data, sizeof(num_data));

        for (unsigned i = 0; i < num_data; ++i)
        {
            int num;
            ifs.read((char*)&num, sizeof(num));
            cout << num << endl;
        }*/

        /*unsigned str_len;
        ifs.read((char*)&str_len, sizeof(str_len));

        string str;
        str.resize(str_len);
        ifs.read(&str[0], str_len);

        cout << str << endl;*/

        //ifs.close(); // not necessary
    }

    return 0;
}
```
### 파일의 임의 위치 접근하기
```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // exit()
#include <sstream>

using namespace std;

int main()
{
    const string filename = "my_file.txt";

    // make a file
    {
        ofstream ofs(filename);

        for (char i = 'a'; i <= 'z'; ++i)
            ofs << i;
        ofs << endl;
    }

    // read the file
    {
        ifstream ifs("my_file.txt");

        ifs.seekg(5);//ifs.seekg(5, ios::beg);
        cout << (char)ifs.get() << endl;

        ifs.seekg(5, ios::cur);
        cout << (char)ifs.get() << endl;

        //ifs.seekg(-5, ios::end);

        ifs.seekg(0, ios::end);
        cout << ifs.tellg() << endl;

        /*string str;
        getline(ifs, str);

        cout << str << endl;*/
    }

    {
       fstream iofs(filename);

       iofs.seekg(5);
       cout << (char)iofs.get() << endl; // read

       iofs.seekp(5); // iofs.seekg(5);
       iofs.put('A'); // write
    }

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
