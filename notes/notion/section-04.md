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
## 🔥 헷갈린 것들 / 질문
-
## ✅ 복습 체크
- [ ] 강의 완주
- [ ] 코드 직접 따라 침
- [ ] 복습 1회
