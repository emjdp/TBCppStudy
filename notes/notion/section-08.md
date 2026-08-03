---
강의 수: 16
상태: 진행 중
섹션 번호: 8
섹션명: 섹션 8. 함수
완료일: null
완료한 강의 수: 3
중요도: ⭐ 중요
진도율: 19
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
