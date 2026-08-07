---
강의 수: 16
상태: 완료
섹션 번호: 8
섹션명: 섹션 8. 함수
완료일:
  end: null
  start: 2026-08-07
  time_zone: null
완료한 강의 수: 16
중요도: ⭐ 중요
진도율: 100
총 시간: 3시간 11분
---

# 섹션 8. 함수

## 📝 핵심 개념 정리
값/참조/주소 전달 차이는 시험 단골. 확실히 정리하기
### **값에 의한 전달**
```cpp
#include <iostream>

using namespace std;

void doSomething(int y) // y 선언 후 값 복사
{
    cout << "In func " << y << " " << &y << endl;
}

int main()
{
    doSomething(5); // 값에 의한 전달

    int x = 6;

    cout << "In main " << x << " " << &x << endl;
    doSomething(x); // x가 전달되는 것이 아니라 6이 전달됨.
}
```
int x = 6; 이후 x를 넣어도 x가 전달되는게 아니라 값 6이 복사가 되는 것.
### **참조에 의한 인수 전달**
```cpp
void addOne(int &y)
{
    cout << "in fn " << y << " " << &y << endl;
    y += 1;
}

typedef int* pint;
void foo(pint &ptr) // (int *&ptr) 랑 같음
{
    cout << ptr << " " << &ptr << endl;
}
```
```cpp
void foo(int*& ptr)
{
    cout << ptr << " " << &ptr << endl;
}
```
int *&ptr; 이건 뭘까?<br>→ (int\*) &ptr 으로 보면 됨<br>아니면<br>typedef int\* pint;<br>pint &ptr*
<columns>
	<column ratio="50">
		### **주소에 의한 인수 전달**
	</column>
	<column ratio="50">
		<br>
	</column>
</columns>
```cpp
#include <iostream>
using namespace std;

typedef int* pint;
void foo(pint ptr) //int* ptr // 값에 의한 전달이랑 같음
{
    cout << *ptr << " " << ptr << " " << &ptr << endl;
}

int main()
{
    int value = 5;

    cout << value << " " << &value << endl;

    int* ptr = &value;

    cout << &ptr << endl;
    foo(ptr);
    foo(&value);

    return 0;
}
```
내부적으로는 값에 의한 전달
```cpp
#include <iostream>
using namespace std;

void foo(double degrees, double *sin_out, double *cos_out)
{
    *sin_out = 1.0;
    *cos_out = 2.0;
}

int main()
{
    double degrees = 30;
    double sin, cos;

    foo(degrees, &sin, &cos);

    cout << sin << " " << cos << endl;

    return 0;
}
```
### **다양한 반환 값들**
### 함수 반환 방식 정리
<table header-row="true">
<tr>
<td>반환 방식</td>
<td>예시</td>
<td>의미 / 용도</td>
<td>주의점 및 현대 C++ 권장사항</td>
</tr>
<tr>
<td>값 반환</td>
<td>`T func()`</td>
<td>새로운 결과값을 호출자에게 전달</td>
<td>가장 기본적인 선택. RVO와 이동 연산 덕분에 큰 객체도 보통 효율적</td>
</tr>
<tr>
<td>참조 반환</td>
<td>`T& func()`</td>
<td>기존 객체를 직접 수정하거나 복사 없이 접근</td>
<td>반환 대상이 함수 종료 후에도 살아 있어야 함. 지역 변수의 참조 반환 금지</td>
</tr>
<tr>
<td>주소 반환</td>
<td>`T* func()`</td>
<td>객체의 위치를 전달하며 `nullptr` 표현 가능</td>
<td>객체 수명과 소유권이 불분명할 수 있음. 소유권 전달에는 스마트 포인터 사용</td>
</tr>
<tr>
<td>구조체 반환</td>
<td>`Result func()`</td>
<td>여러 결과를 의미 있는 이름으로 묶어서 반환</td>
<td>결과의 의미가 명확해 여러 값을 반환할 때 가장 읽기 좋은 방식</td>
</tr>
<tr>
<td>튜플 반환</td>
<td>`std::tuple<T1, T2> func()`</td>
<td>여러 값을 간단히 묶어서 반환</td>
<td>각 값의 이름이 없어 의미가 흐려질 수 있음. 구조적 바인딩과 함께 사용</td>
</tr>
<tr>
<td>선택적 값 반환</td>
<td>`std::optional<T> func()`</td>
<td>결과가 있을 수도, 없을 수도 있음을 표현</td>
<td>실패를 `nullptr`이나 특수한 값으로 표현하는 것보다 명확함</td>
</tr>
<tr>
<td>스마트 포인터 반환</td>
<td>`std::unique_ptr<T> func()`</td>
<td>생성한 객체의 소유권을 호출자에게 전달</td>
<td>직접 `new`한 주소를 반환하는 방식보다 안전하고 소유권이 명확함</td>
</tr>
</table>
> 기본은 **값 반환**, 여러 결과는 **구조체**, 기존 객체를 가리킬 때는 **수명을 보장한 참조/포인터**, 소유권 전달은 **스마트 포인터**를 사용
### inline
과거에는 함수 호출 비용을 줄이려고 사용했으나 현대 컴파일러는 알아서 인라인 여부를 판단한다. 현재는 주로 헤더에 함수나 변수를 정의할 때 중복 정의를 허용하는 ODR 관련 기능으로 사용
## 함수 오버로딩
```cpp
int add(int x, int y)
{
    return x + y;
}

int add(double x, double y)
{
    return x + y;
}
```
함수명이 같아도 파라미터(매개변수)가 다르면 다른 함수
## 매개변수의 기본값

```cpp
void print(int x = 10, int y = 20, int z = 30); // in header

void print(int x, int y, int z)
{
    cout << x << " " << y << " " << z << endl;
}
```
기본값 설정은 위아래에서 하나만
```cpp
void print1(std::string str) {}
void print1(char ch = ' ') {}

...

print();
```
가능. char로 받은거고 기본값 ‘ ‘ 들어감.
### 함수 포인터
나중에 호출할 함수를 변수처럼 저장해서 사용
```cpp
int func(int x)
{
    return 5;
}

int goo(int x)
{
    return 10;
}

int main()
{
    int(*fcnptr)(int) = func;

    cout << fcnptr(1) << endl;

    fcnptr = goo;
```
```cpp
void printNumbers(const array<int, 10>& my_array, bool print_even)
{
    for (auto element : my_array)
    {
        if (print_even && element % 2 == 0) cout << element;
        if (!print_even && element % 2 == 1) cout << element;
    }
    cout << endl;
}

int main()
{
    std::array<int, 10> my_array{ 0,1,2,3,4,5,6,7,8,9 };

    printNumbers(my_array, true);
    printNumbers(my_array, false);
    return 0;
}

```
위에꺼에 함수 포인터를 적용하면
```cpp
bool isEven(const int& number)
{
    if (number % 2 == 0) return true;
    else return false;
}

bool isOdd(const int& number)
{
    if (number % 2 != 0) return true;
    else return false;
}

void printNumbers(const array<int, 10>& my_array, bool (*check_fcn)(const int&))
{
    for (auto element : my_array)
    {
        if (check_fcn(element) == true) cout << element;
    }
    cout << endl;
}

int main()
{
    std::array<int, 10> my_array{ 0,1,2,3,4,5,6,7,8,9 };

    printNumbers(my_array, isEven);
    printNumbers(my_array, isOdd);
    return 0;
}
```
<br><br>`bool (check_fcn)(const int&)` 같은게 반복 된다면<br>`typedef bool(check_fcn_t)(const int&);` check_fcn_t check_fcn = isEven 이렇게 단축 가능
다음과 같은 방법도 존재
```cpp
#include <iostream>
#include <array>
#include <functional>

using namespace std;

bool isEven(const int& number)
{
    if (number % 2 == 0) return true;
    else return false;
}

bool isOdd(const int& number)
{
    if (number % 2 != 0) return true;
    else return false;
}

void printNumbers(const array<int, 10>& my_array, std::function<bool(const int&)> check_fcn)
{
    for (auto element : my_array)
    {
        if (check_fcn(element) == true) cout << element;
    }
    cout << endl;
}

int main()
{
    std::array<int, 10> my_array{ 0,1,2,3,4,5,6,7,8,9 };
    std::function<bool(const int&)> fcnptr = isEven;

    printNumbers(my_array, fcnptr);
    fcnptr = isOdd;

    printNumbers(my_array, fcnptr);



    return 0;
}
```
### 스택과 힙
#### 1. 프로그램의 메모리 영역
```plain text
┌──────────────────────────────┐
│ Heap                         │
│ 동적으로 할당한 메모리         │
│ new / delete로 관리           │
├──────────────────────────────┤
│ Stack                        │
│ 지역 변수, 매개변수, 호출 정보  │
├──────────────────────────────┤
│ Data                         │
│ 초기값이 있는 전역/static 변수 │
├──────────────────────────────┤
│ BSS                          │
│ 0으로 초기화되거나             │
│ 초기화되지 않은 전역/static 변수│
├──────────────────────────────┤
│ Code                         │
│ 프로그램의 실행 명령어         │
└──────────────────────────────┘
```
---
#### 2. 스택과 힙의 차이
<table header-row="true">
<tr>
<td>구분</td>
<td>스택(Stack)</td>
<td>힙(Heap)</td>
</tr>
<tr>
<td>주된 용도</td>
<td>지역 변수, 매개변수, 함수 호출 정보</td>
<td>실행 중 필요한 동적 메모리</td>
</tr>
<tr>
<td>관리 방법</td>
<td>스코프에 따라 자동 관리</td>
<td>`new`, `delete` 또는 컨테이너로 관리</td>
</tr>
<tr>
<td>할당 속도</td>
<td>일반적으로 빠름</td>
<td>일반적으로 스택보다 느림</td>
</tr>
<tr>
<td>크기</td>
<td>비교적 작음</td>
<td>비교적 큼</td>
</tr>
<tr>
<td>수명</td>
<td>해당 스코프가 끝날 때까지</td>
<td>직접 해제할 때까지</td>
</tr>
<tr>
<td>할당 방식</td>
<td>함수 호출에 따라 차례로 쌓임</td>
<td>필요한 크기의 빈 공간을 찾아 할당</td>
</tr>
</table>
스택은 함수가 호출될 때 쌓이고, 함수가 끝나면 역순으로 제거
```plain text
호출 순서: main → first → second
종료 순서: second → first → main
```
---
#### 3. 함수 호출과 스택
```cpp
#include <iostream>

int g_i = 0;

int second(int x)
{
    return 2 * x;
}

int first(int x)
{
    int y = 3;
    return second(x + y);
}

int main()
{
    int a = 1;
    int b;

    b = first(a);
    std::cout << b << '\n';

    return 0;
}
```
`main()`이 `first()`를 호출하고, `first()`가 다시 `second()`를 호출
`second()`가 실행 중일 때의 스택
```plain text
┌──────────────────────┐
│ second()             │ ← 가장 최근에 호출됨
│ 매개변수 x            │
├──────────────────────┤
│ first()              │
│ 매개변수 x, 지역변수 y│
├──────────────────────┤
│ main()               │
│ 지역변수 a, b         │
└──────────────────────┘
```
`second()`가 끝나면 `second()`의 스택 영역이 제거되고, 이후 `first()`, `main()` 순서로 제거
---
#### 4. 스택 오버플로
다음과 같이 매우 큰 지역 배열을 선언하면 스택 공간이 부족해짐
```cpp
int main()
{
    int array[1'000'000];

    return 0;
}
```
필요한 메모리가 스택의 제한보다 크면 스택 오버플로가 발생
큰 배열이 필요하다면 모던C++에서는 보통 `std::vector`를 사용
```cpp
#include <vector>

int main()
{
    std::vector<int> array(1'000'000);

    return 0;
}
```
---
#### 5. 힙에 배열 할당하기
```cpp
int main()
{
    int* ptr = nullptr;

    ptr = new int[1'000'000];

    ptr[0] = 10;
    ptr[1] = 20;

    delete[] ptr;
    ptr = nullptr;

    return 0;
}
```
메모리 구조를 단순화하면 다음과 같다.
```plain text
Stack                          Heap

┌──────────────────┐          ┌──────────────────────┐
│ ptr              │ ───────▶ │ int 배열 1,000,000개 │
│ 힙의 주소를 저장 │          │ new int[1'000'000]   │
└──────────────────┘          └──────────────────────┘
```
- `ptr`은 `main()`의 지역 변수이므로 일반적으로 스택에 저장
- 실제 배열은 `new[]`로 생성했으므로 힙에 저장
- `ptr`에는 배열 자체가 아니라 배열이 있는 메모리 주소가 저장
---
#### 6. `delete[]`를 실행하면 어떻게 되는가?
```cpp
int* ptr = new int[1000];

delete[] ptr;
```
`delete[] ptr`을 실행하면 힙에 있던 배열의 수명 끝
```plain text
delete[] 실행 직후

Stack                          Heap

┌──────────────────────┐      ┌─────────────────────┐
│ ptr                  │ ───▶ │ 이미 해제된 메모리  │
│ 이전 주소가 남아 있음│      │ 더 이상 사용 불가   │
└──────────────────────┘      └─────────────────────┘
```
이처럼 해제된 메모리 주소를 계속 가지고 있는 포인터를 댕글링 포인터라고 함
```cpp
delete[] ptr;

ptr[0] = 10; // 잘못된 사용
```
```cpp
delete[] ptr;
ptr = nullptr;
```
`nullptr`를 대입하면 포인터가 해제된 주소를 더 이상 가리키지 않게 됨
---
#### 7. `delete[]`하지 않고 함수가 끝나는 경우
```cpp
void initArray()
{
    int* ptr2 = new int[1000];

    // delete[] ptr2;가 없음
}

int main()
{
    initArray();

    return 0;
}
```
`initArray()`가 실행 중일 때는 다음과 같은 상태이다.
```plain text
Stack                          Heap

┌───────────────────┐         ┌──────────────────┐
│ initArray()       │         │ int 배열 1000개 │
│ ptr2 ─────────────┼───────▶ │                  │
├───────────────────┤         └──────────────────┘
│ main()            │
└───────────────────┘
```
`initArray()`가 끝나면 지역 변수 `ptr2`는 스택에서 사라짐
하지만 `new int[1000]`으로 만든 힙 메모리는 자동으로 해제되지 않음
```plain text
initArray() 종료 후

Stack                          Heap

┌───────────────────┐         ┌──────────────────┐
│ main()            │         │ int 배열 1000개 │
└───────────────────┘         │ 아직 할당되어 있음│
                              └──────────────────┘

배열 주소를 가지고 있던 ptr2는 사라졌다.
따라서 배열에 접근하거나 delete[]할 방법이 없다.
```
힙 메모리는 계속 사용 중이지만, 함수를 나오면서 주소를 가지고 있던 포인터가 사라졌기 때문에 접근도 해제도 할 수 없는 상태이다. 즉 메모리 누수.
---
#### 8. 함수가 만든 배열을 나중에도 사용하려면
함수가 끝난 뒤에도 배열을 사용하려면 배열의 주소를 호출자에게 전달해야 한다.
```cpp
int* makeArray()
{
    int* ptr = new int[1000];
    return ptr;
}

int main()
{
    int* array = makeArray();

    array[0] = 10;
    array[1] = 20;

    delete[] array;
    array = nullptr;

    return 0;
}
```
```plain text
makeArray() 종료 후

Stack                          Heap

┌──────────────────┐          ┌──────────────────┐
│ main()           │          │ int 배열 1000개 │
│ array ───────────┼────────▶ │                  │
└──────────────────┘          └──────────────────┘
```
---
#### 9. 현대 C++에서 권장하는 방법
직접 `new[]`와 `delete[]`를 관리하기보다 `std::vector`를 사용하는 것이 안전
```cpp
#include <vector>

std::vector<int> makeArray()
{
    return std::vector<int>(1000);
}

int main()
{
    std::vector<int> array = makeArray();

    array[0] = 10;
    array[1] = 20;

    // delete[]할 필요가 없다.
    // array의 수명이 끝나면 자동으로 정리된다.

    return 0;
}
```
동적 배열의 소유권을 명시적으로 관리해야 한다면 `std::unique_ptr`도 사용할 수 있음
```cpp
#include <memory>

int main()
{
    auto array = std::make_unique<int[]>(1000);

    array[0] = 10;

    // 수명이 끝나면 자동으로 해제된다.
    return 0;
}
```
---
#### 스택과 힙 최종 요약
```plain text
new
 ↓
힙에 메모리 할당
 ↓
유효한 포인터를 통해 사용
 ↓
더 이상 필요하지 않으면 delete[]
 ↓
포인터에 nullptr 대입
```
- 스택 변수는 스코프가 끝나면 자동으로 정리된다.
- 힙 메모리는 포인터 변수가 사라져도 자동으로 정리되지 않는다.
- `delete[]`한 메모리는 더 이상 사용할 수 없다.
- `delete[]`하지 않았더라도 주소를 잃어버리면 사용할 수 없다.
- 주소를 잃은 채 남아 있는 힙 메모리를 메모리 누수라고 한다.
- `nullptr`는 메모리를 다시 사용할 수 있게 하는 것이 아니다.
- `nullptr`는 해제된 주소를 실수로 사용하는 것을 방지하기 위한 값이다.
- 현대 C++에서는 가능하면 `std::vector`와 스마트 포인터를 사용한다.
---
### std vector 스택처럼 쓰기
```cpp
// vector 사용 기초
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //int* v = new int[3] {1, 2, 3};
    std::vector<int> v{ 1,2,3 };

    v.resize(2);
    v.reserve(1024);

    for (auto& e : v)
        cout << e << " ";
    cout << endl;

    cout << v.size() << " " << v.capacity() << endl;
    return 0;
}
```
```cpp
#include <iostream>
#include <vector>

using namespace std;

void printStack(const std::vector<int>& stack)
{
    for (auto& e : stack)
        cout << e << " ";
    cout << endl;
}

int main()
{
    std::vector<int> stack;

    //stack.reserve(1024);

    stack.push_back(3);
    printStack(stack);

    stack.push_back(5);
    printStack(stack);

    stack.push_back(7);
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    return 0;
}
```
왜 스택을 벡터로 구현 할까? → reserve 해두면 push_back을 할 때 capacity를 늘릴 필요 없음
## 재귀함수

```cpp
void countDown(int count)
{
    cout << count << endl;

    if(count > 0)
        countDown(count - 1);
}

int sumTo(int sumto)
{
    if (sumto <= 0)
        return 0;
    else if (sumto <= 1)
        return 1;
    else
        return sumTo(sumto - 1) + sumto;
}

int piBo(int n) // 0 1 1 2 3 5 8 13
{
    if (n <= 1)
        return n;

    return piBo(n - 1) + piBo(n -2);
}
```
## 방어적 프로그래밍

```cpp
    //semantic errors

    int x;
    cin >> x;

    if (x >= 5) // = 빼야함
        cout << "x is greater than 5" << endl;

    //violated assumption

    string hello = "Hello, my name is Jack Jack";

    cout << "Input from 0 to " << hello.size() - 1 << endl;

    while (true)
    {
        int ix;
        cin >> ix;

        if (ix >= 0 && ix <= hello.size() - 1)
        {
            cout << hello[ix] << endl;
            break;
        }
        else
            cout << hello[ix] << endl;
    }
```
## 단언하기 assert
    //assert(false); // 디버그 모드에서만 작동<br><br>    int number = 4;<br>    // ...<br>    assert(number == 5);<br><br>    const int x = 4<br>    static_assert(x == 4, "x should be 5"); // 컴파일 타임에 결정되어야 쓸 수 있음
```cpp
#include <iostream>
#include <cassert>
#include <array>
using namespace std;

void printValue(const std::array<int, 5>& my_array, const int& ix)
{
    assert(ix >= 0);
    assert(ix <= my_array.size() - 1);

    std::cout << my_array[ix] << std::endl;
}

int main()
{
    std::array<int, 5> my_array{ 1,2,3,4,5 };
    printValue(my_array, 100);

    return 0;
}
```
## 명령줄 인수
 실행할때 OOOOO.exe 뒤에 쓰던가<br>properties → debuging → commend arguments 에 쓰면 됨
```cpp
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    for (int count = 0; count < argc; ++count)
    {
        std::string argv_single = argv[count];

        if (count == 1)
        {
            int input_number = std::stoi(argv_single);
            cout << input_number + 1 << endl;
        }

        cout << argv_single << endl;

    }

    return 0;
}
```
## 생략부호
```cpp
#include <iostream>
#include <cstdarg> // for ellipsis
using namespace std;

double findAverage(int count, ...)
{
    double sum = 0;

    va_list list;

    va_start(list, count);

    for (int arg = 0; arg < count; ++arg)
        sum += va_arg(list, int);

    va_end(list);

    return sum / count;
}

int main()
{
    cout << findAverage(3, 3, 5, 24, 54, 7) << endl;
    cout << findAverage(2, 3, 5, "Hello", 'c') << endl;

    return 0;
}
```
## 💻 코드 스니펫
```cpp
// 직접 따라 친 코드 중 기억할 것
```
## 🔥 헷갈린 것들 / 질문
### 2. 값에 의한 전달
다음 코드의 출력 결과는 무엇인가요?
```plain text
void increase(int number)
{
    number++;
}

int value = 5;
increase(value);

std::cout << value;
```
A. `5`
B. `6`
C. 쓰레기 값
D. 컴파일 오류
**정답: A**
**해설**
`number`에는 `value`의 복사본이 전달됩니다. 함수 안에서 `number`를 증가시켜도 원본 변수 `value`는 변경되지 않습니다.
---
### 3. 참조에 의한 전달
다음 코드의 출력 결과는 무엇인가요?
```plain text
void increase(int& number)
{
    number++;
}

int value = 5;
increase(value);

std::cout << value;
```
A. `5`
B. `6`
C. 쓰레기 값
D. 컴파일 오류
**정답: B**
**해설**
`int& number`는 원본 변수 `value`의 별명처럼 동작합니다. 따라서 `number++`은 실제로 원본 변수 `value`를 증가시킵니다.
---
### 4. 값 전달과 참조 전달의 비교
다음 코드의 출력 결과는 무엇인가요?
```plain text
void change(int a, int& b)
{
    a = 100;
    b = 200;
}

int x = 10;
int y = 20;

change(x, y);

std::cout << x << ' ' << y;
```
A. `10 20`
B. `100 20`
C. `10 200`
D. `100 200`
**정답: C**
**해설**
`a`는 값으로 전달되므로 `x`의 복사본입니다. 따라서 `a`를 변경해도 `x`는 그대로 `10`입니다.
`b`는 참조로 전달되므로 `y`와 같은 변수를 가리킵니다. 따라서 `b = 200`을 실행하면 `y`도 `200`으로 변경됩니다.
## ✅ 복습 체크
- [x] 강의 완주
- [x] 코드 직접 따라 침
- [x] 복습 1회
