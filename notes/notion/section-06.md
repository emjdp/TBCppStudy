---
강의 수: 10
상태: 완료
섹션 번호: 6
섹션명: 섹션 6. 흐름 제어
완료일:
  end: null
  start: 2026-07-28
  time_zone: null
완료한 강의 수: 10
중요도: 기본
진도율: 100
총 시간: 2시간 30분
---

# 섹션 6. 흐름 제어

## 📝 핵심 개념 정리
```cpp
    #include <cstdlib>
    exit(0); // 무조건 종료해야 할 때
```
    unsigned int n = 10; //이걸로 감소하는 만들면 오버플로우 발생 할 수도 있음.<br><br>    몇번에 한번 실행 하고 싶다<br>    -\> if (count % 5 == 0) cout \<\< "Hello" \<\< cout \<\< endl;
do-while 문
```cpp
    int selection;

    do
    {
        cout << "1. add"    << endl;
        cout << "2. sub"    << endl;
        cout << "3. mult"   << endl;
        cout << "4. div"    << endl;
        cin >> selection;
    } while (selection <= 0 || selection >= 5);

    cout << "You selected " << selection << endl;
```
for (초기화 ; 조건식 ; 증감식)
1. **초기화**
2. **조건식 검사** (거짓이면 본문을 한 번도 실행하지 않고 즉시 종료)
3. **본문 실행**
4. **증감식 실행**
5. **조건식 검사** → 본문 실행 → 증감식 실행 (이후 무한 반복)
```cpp
    int count = 0;
    for (; count < 10; ++count) // iteration // int count = 0 밖에 빼두고 비워도 됨
```
for문 버전의 while(true)<br>for (; true ; count++)<br>for (; ; count++)
## 💻 코드 스니펫
```cpp
    if (a > 0 && b > 0)
        cout << "both number are positive" << endl;
    else if (a > 0 || b > 0)
        cout << "one of the number is positive" << endl;
    else
        cout << "Neither number is positive" << endl;

    if (a > 10)
        cout << "A" << endl;
    else if (x == -1)
        return 0; // exit(0)
    else if (x < 0)
        cout << "B " << endl;

    cout << "Hello " << endl;


    if (x > 10)
        ; // null statement

    if (x = 0) // x = 0; if(x)
        cout << x << endl; // 실행 안됨
    cout << x << endl;

```
```cpp
int min(int x, int y)
{
    //if (x > y) return y;
    //else       return x;
    return (x > y) ? y : x;
}
```
```cpp
    switch (x)
    {
        //int b = 5; 선언은 되지만 초기화는 case 안에서만 가능
    case 0:
        cout << "Zero";
        [[fallthrough]];
    case 1:
        cout << "One";
        [[fallthrough]];
    case 2:
        cout << "Two";
        [[fallthrough]];
    case 3:
        cout << "three";
        int b;
        break;
    case 4:
        cout << "four" << b;
        //문제 없음 case 3에 넣어둬도 switch 바로 밑에 넣는거랑 같음.
        //이딴짓은 그냥 안하는게 나음.
        // 내부에서 b를 쓰는거면 switch를 하나의 {}로 감싸로 맨 위에 int b;
        // 해서 처리하는게 좋은 선택.
    }
```
```cpp
// goto 쓸 일이 거의 없을수도 있지만.

#include <iostream>
#include <cmath> // sqrt()

using namespace std;

int main()
{
    double x;

tryAgain : // label
    cout << "Enter a non-negative number" << endl;
    cin >> x;

    if (x < 0.0)
        goto tryAgain; // 잘 안쓰임

    cout << sqrt(x) << endl;

/*    goto skip; // 순서가 잘못됨.
    int y = 5;

skip:
    y += 3;*/

    return 0;
}
```
```cpp
    bool escape_flag = false;
    char ch;
    while (!escape_flag)
    {
        cin >> ch;
        cout << ch << " " << c++ << endl;
        if (ch == 'x')
            escape_flag = true;
    }
```
```cpp
#include <iostream>
#include <cstdlib> // std::radn(), std::srand()
#include <ctime>   // std::time()
#include <random>
using namespace std;

unsigned int PRNG() // Pseudo Random Number Generator
{
    static unsigned int seed = 5523; // seed number

    seed = 8253729 * seed + 2396403;

    return seed % 32768;
}

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (RAND_MAX + 1.0);

    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

int main()
{
/*    for (int count = 1; count <= 100; ++count)
    {
        cout << PRNG() << "\t";

        if (count % 5 == 0) cout << endl;
    }*/

    //std::srand(5323); // seed. 디버깅 할 때는 시드 고정하는게 편함
    std::srand(static_cast<unsigned int>(std::time(0)));
    for (int count = 1; count <= 100; ++count)
    {
        //cout << std::rand() << "\t";
        cout << getRandomNumber(5,8) << "\t";

        if (count % 5 == 0) cout << endl;
    }


    std::random_device rd;
    std::mt19937 mesenne(rd());
    std::uniform_int_distribution<> dice(1, 6);

    for (int count = 1; count <= 20; ++count)
        cout << dice(mesenne) << endl;
    return 0;
}
```
## 🔥 헷갈린 것들 / 질문
- switch-case `Fallthrough`  하면 IDE에서 경고 밑줄 뜨는  것은 어떻게 해결?<br>→ c++17부터 `[[fallthrough]];`로 속성 추가 가능
## ✅ 복습 체크
- [x] 강의 완주
- [x] 코드 직접 따라 침
- [x] 복습 1회
