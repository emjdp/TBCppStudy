---
강의 수: 9
상태: 진행 중
섹션 번호: 4
섹션명: 섹션 4. 연산자들
완료일: null
완료한 강의 수: 1
중요도: 기본
진도율: 11
총 시간: 3시간 38분
---

# 섹션 4. 연산자들

## 📝 핵심 개념 정리
강의 들으면서 여기에 내 언어로 정리하기
<table header-row="true">
<tr>
<td>Order</td>
<td>Operator</td>
<td>Description</td>
<td>Associativity</td>
</tr>
<tr>
<td>1highest</td>
<td>`::`</td>
<td>[Scope resolution](https://en.wikipedia.org/wiki/Scope_resolution_operator#C.2B.2B) (C++ only)</td>
<td>None</td>
</tr>
<tr>
<td>2</td>
<td>`++`</td>
<td>Postfix increment</td>
<td>Left-to-right</td>
</tr>
<tr>
<td></td>
<td>`--`</td>
<td>Postfix decrement</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`()`</td>
<td>Function call</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`[]`</td>
<td>Array subscripting</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`.`</td>
<td>Element selection by reference</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`->`</td>
<td>Element selection through pointer</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`typeid()`</td>
<td>[Run-time type information](https://en.wikipedia.org/wiki/Run-time_type_information) (C++ only) (see [typeid](https://en.wikipedia.org/wiki/Typeid))</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`const_cast`</td>
<td>Type cast (C++ only) (see [const_cast](https://en.wikipedia.org/wiki/Const_cast))</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`dynamic_cast`</td>
<td>Type cast (C++ only) (see [dynamic cast](https://en.wikipedia.org/wiki/Dynamic_cast))</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`reinterpret_cast`</td>
<td>Type cast (C++ only) (see [reinterpret_cast](https://en.wikipedia.org/wiki/Reinterpret_cast))</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`static_cast`</td>
<td>Type cast (C++ only) (see [static_cast](https://en.wikipedia.org/wiki/Static_cast))</td>
<td></td>
</tr>
<tr>
<td>3</td>
<td>`++`</td>
<td>Prefix increment</td>
<td>Right-to-left</td>
</tr>
<tr>
<td></td>
<td>`--`</td>
<td>Prefix decrement</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`+`</td>
<td>Unary plus</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`-`</td>
<td>Unary minus</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`!`</td>
<td>Logical NOT</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`~`</td>
<td>Bitwise NOT ([ones' complement](https://en.wikipedia.org/wiki/Ones'_complement))</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`(type)`</td>
<td>Type cast</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`*`</td>
<td>Indirection (dereference)</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`&`</td>
<td>Address-of</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`sizeof`</td>
<td>[Sizeof](https://en.wikipedia.org/wiki/Sizeof)</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`_Alignof`</td>
<td>Alignment requirement (since C11)</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`new`, `new[]`</td>
<td>Dynamic memory allocation (C++ only)</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`delete`, `delete[]`</td>
<td>Dynamic memory deallocation (C++ only)</td>
<td></td>
</tr>
<tr>
<td>4</td>
<td>`.*`</td>
<td>Pointer to member (C++ only)</td>
<td>Left-to-right</td>
</tr>
<tr>
<td></td>
<td>`->*`</td>
<td>Pointer to member (C++ only)</td>
<td></td>
</tr>
<tr>
<td>5</td>
<td>`*`</td>
<td>Multiplication</td>
<td>Left-to-right</td>
</tr>
<tr>
<td></td>
<td>`/`</td>
<td>Division</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`%`</td>
<td>[Modulo](https://en.wikipedia.org/wiki/Modulo_operation) (remainder)</td>
<td></td>
</tr>
<tr>
<td>6</td>
<td>`+`</td>
<td>Addition</td>
<td>Left-to-right</td>
</tr>
<tr>
<td></td>
<td>`-`</td>
<td>Subtraction</td>
<td></td>
</tr>
<tr>
<td>7</td>
<td>`<<`</td>
<td>[Bitwise](https://en.wikipedia.org/wiki/Bitwise_operation) left shift</td>
<td>Left-to-right</td>
</tr>
<tr>
<td></td>
<td>`>>`</td>
<td>[Bitwise](https://en.wikipedia.org/wiki/Bitwise_operation) right shift</td>
<td></td>
</tr>
<tr>
<td>8</td>
<td>`<=>`</td>
<td>[Three-way comparison](https://en.wikipedia.org/wiki/Three-way_comparison) (Introduced in [C++20](https://en.wikipedia.org/wiki/C++20) - C++ only)</td>
<td>Left-to-right</td>
</tr>
<tr>
<td>9</td>
<td>`<`</td>
<td>Less than</td>
<td>Left-to-right</td>
</tr>
<tr>
<td></td>
<td>`<=`</td>
<td>Less than or equal to</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`>`</td>
<td>Greater than</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`>=`</td>
<td>Greater than or equal to</td>
<td></td>
</tr>
<tr>
<td>10</td>
<td>`==`</td>
<td>Equal to</td>
<td>Left-to-right</td>
</tr>
<tr>
<td></td>
<td>`!=`</td>
<td>Not equal to</td>
<td></td>
</tr>
<tr>
<td>11</td>
<td>`&`</td>
<td>Bitwise AND</td>
<td>Left-to-right</td>
</tr>
<tr>
<td>12</td>
<td>`^`</td>
<td>Bitwise XOR (exclusive or)</td>
<td>Left-to-right</td>
</tr>
<tr>
<td>13</td>
<td>`|`</td>
<td>Bitwise OR (inclusive or)</td>
<td>Left-to-right</td>
</tr>
<tr>
<td>14</td>
<td>`&&`</td>
<td>Logical AND</td>
<td>Left-to-right</td>
</tr>
<tr>
<td>15</td>
<td>`||`</td>
<td>Logical OR</td>
<td>Left-to-right</td>
</tr>
<tr>
<td>16</td>
<td>`co_await`</td>
<td>Coroutine processing (C++ only)</td>
<td>Right-to-left</td>
</tr>
<tr>
<td></td>
<td>`co_yield`</td>
<td></td>
<td></td>
</tr>
<tr>
<td>17</td>
<td>`?:`</td>
<td>[Ternary conditional operator](https://en.wikipedia.org/wiki/Ternary_conditional_operator)</td>
<td>Right-to-left</td>
</tr>
<tr>
<td></td>
<td>`=`</td>
<td>Direct assignment</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`+=`</td>
<td>Assignment by sum</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`-=`</td>
<td>Assignment by difference</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`*=`</td>
<td>Assignment by product</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`/=`</td>
<td>Assignment by quotient</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`%=`</td>
<td>Assignment by remainder</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`<<=`</td>
<td>Assignment by bitwise left shift</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`>>=`</td>
<td>Assignment by bitwise right shift</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`&=`</td>
<td>Assignment by bitwise AND</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`^=`</td>
<td>Assignment by bitwise XOR</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`|=`</td>
<td>Assignment by bitwise OR</td>
<td></td>
</tr>
<tr>
<td></td>
<td>`throw`</td>
<td>Throw operator (exceptions throwing, C++ only)</td>
<td></td>
</tr>
<tr>
<td>18lowest</td>
<td>`,`</td>
<td>[Comma](https://en.wikipedia.org/wiki/Comma_operator)</td>
<td>Left-to-right</td>
</tr>
</table>
[https://en.wikipedia.org/wiki/Operators_in_C_and_C](https://en.wikipedia.org/wiki/Operators_in_C_and_C)
0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>9<br>10 = 10\^1 + 0<br>11 = 10\^1 + 1<br>12<br>13<br>…<br>337 = 300 + 30 + 7 = 10\^2 \* 3 + 10 \^ 1 \* 3 + 10\^0 \* 7
---
0<br>1<br>10 = 2\^1\*1 + 2\^0\*0 = 2<br>11 = 2\^1\*1 + 2\^1\*1 = 3<br><br><br>7654 3210<br>0101 1110<br>2\^7\*0 + 64\*1 + 32\*0 + 16\*1 + 8\*1 + 4\*1 + 2\*1 + 2\^0\*0<br>= 94<br>
148 / 2 = 74 r0<br>74 / 2 = 37 r0<br>37 / 2 = 18 r1<br>18 / 2 = 9 r0<br>9 / 2 = 4 r1<br>4 / 2 = 2 r0<br>2 / 2 = 1 r0<br>1 / 2 = 0 r1
1001 0100
-5 <br><span color="green">0</span>000 0101 / <span color="green">맨 앞은 부호 </span>← 5<br>보수 complement<br>1111 1010<br>1111 1011 ← -5 / 1을 더해서 0의 표현을 통일시킴<br><br>1을 안 더하면<br>0000 0000<br>1111 1111<br>이렇게 공존.<br>
1001 1110 음수<br>0110 0001<br>0110 0010 → 98 → -98<br>
singned vs unsigned
1001 1110 → 2\^7\*1 + 2\^4\*1 + 2\^3\*1 + 2\^2\*1 + 2\^1\*1
## 💻 코드 스니펫
```cpp
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x = 4 / 2 * 3; // Associativity Left-to-right
    // ^ 가 제곱으로 안 쓰임. bitwise XOR
    int y = std::pow(2, 3);
    cout << y << endl;
    return 0;
}

```
```cpp
    int x = 7;
    int y = 4;

    cout << x / y << endl; // 1
    cout << float(x) / y << endl; // 1.75
    cout << x / float(y) << endl; // 1.75
    cout << float(x) / float(y) << endl; // 1.75
    cout << -5 / 2 << endl; // -2 -0.5는 버림

    int  z = x;
    z += y; // z = z + y
```
```cpp
    int x = 6, y = 6;
    cout << x << " " << y << endl; // 6 6
    cout << ++x << " " << --y << endl; // 7 5
    cout << x << " " << y << endl; // 7 5
    cout << x++ << " " << y-- << endl; // 7 5
    cout << x << " " << y << endl; // 8 4

```
```cpp
#include <iostream>
#include <cmath>

int main()
{
    using namespace std;

    double d1(100 - 99.99); // 0.001
    double d2(10 - 9.99); // 0.001

    const double epsilon = 1e-10;

    if (std::abs(d1 - d2) < epsilon)
        cout << "Approximately equal" << endl;
    else
        cout << "Not equal" << endl;

    cout << d1 << endl;
    cout << d2 << endl;

    cout << std::abs(d1 - d2) << endl;

    if (d1 == d2)
        cout << "equal" << endl;
    else
    {
        cout << "Not equal" << endl;
        if (d1 > d2) cout << "d1 > d2" << endl;
        else
            cout << "d1 < d2" << endl;
    }
```
```cpp
int main()
{
    using namespace std;

    //logical AND &&
    bool x = true;
    bool y = false;

    cout << (x && y) << endl;

    //ex
    bool hit = true;
    int health = 10;

    if (hit == true && health < 20) // if (hit && health < 20) 도 됨
    {
        cout << "die" << endl;
    }
    else
        health -= 20;

    //logical OR ||
    int v = 1;

    if (v == 0 || v == 1)
        cout << "v is 0 or 1" << endl;

    //logical NOT

    int a = 5;
    int b = 7;

    if (x != y)
    {
        cout << " x does not equal y" << endl;
    }
    else
        cout << " x equals y " << endl;

    // short circuit evaluation
    int c = 1;
    int d = 2;

    if (c == 1 && d++ == 2)
    {
        // do something
    }

    cout << d << endl;

    // De Morgan's Law
    !(x || y);
    !x && !y;


    // XOR
    // f f = f
    // f t = t
    // t f = t
    // t t = f
    cout << (x != y) << endl;

    bool v1 = true;
    bool v2 = false;
    bool v3 = false;

    bool r1 = v1 || v2 && v3;
    bool r2 = (v1 || v2) && v3;
    bool r3 = v1 || (v2 && v3); // r1은 이런식으로 계산 됨. &&가 ||보다 우선 순위. 그냥 괄호 처서 하면 실수 위험 없음.
    cout << r1 << endl;
    cout << r2 << endl;

    return 0;
}
```
```cpp
#include <iostream>
#include <bitset>
int main()
{
    using namespace std;
    // << left shift
    // >> right shift
    // ~ , & , |, ^

    unsigned int a = 3;
    cout << std::bitset<8>(a) << " " << a << endl;

    cout << std::bitset<8>(a << 1) << " " << (a << 1) << endl;
    cout << std::bitset<8>(a << 2) << " " << (a << 2) << endl;
    cout << std::bitset<8>(a << 3) << " " << (a << 3) << endl;
    cout << std::bitset<8>(a << 4) << " " << (a << 4) << endl;

    unsigned int b = 1024;
    cout << std::bitset<16>(b) << " " << b << endl;

    cout << std::bitset<16>(b >> 1) << " " << (b >> 1) << endl;
    cout << std::bitset<16>(b >> 2) << " " << (b >> 2) << endl;
    cout << std::bitset<16>(b >> 3) << " " << (b >> 3) << endl;
    cout << std::bitset<16>(b >> 4) << " " << (b >> 4) << endl;

    cout << std::bitset<16>(~b) << " " << (~b) << endl; // ! = logical not. ~ = bitwise not

    unsigned int c = 0b1100;
    unsigned int d = 0b0110;

    cout << c << " " << d << endl;
    cout << std::bitset<4>(c & d) << endl; // bitwise AND
    cout << std::bitset<4>(c | d) << endl; // bitwise OR
    cout << std::bitset<4>(c ^ d) << endl; // bitwise XOR

    // c &= d;

    cout << std::bitset<8>(d >> 2) << " " << (d >> 2) << endl; // 9가 아니라 1이 됨. 벗어나면 사라짐


    return 0;
}

```
## 🔥 헷갈린 것들 / 질문
- <br><br>`cout << x % 2 == 0 ? "even" : "odd" << endl; // 안되는 이유는?`
	(cout \<\< (x % 2 == 0)) ? "even" : ("odd" \<\< endl); 이렇게 해석해 버림
	<br>비트 이동(Shift) 연산은 비트들을 말 그대로 **한쪽 방향으로 밀어내는 연산.<br>**넘어가 버리면 사라짐.
## ✅ 복습 체크
- [ ] 강의 완주
- [ ] 코드 직접 따라 침
- [ ] 복습 1회
