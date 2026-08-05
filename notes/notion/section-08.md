---
강의 수: 16
상태: 진행 중
섹션 번호: 8
섹션명: 섹션 8. 함수
완료일: null
완료한 강의 수: 8
중요도: ⭐ 중요
진도율: 50
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
