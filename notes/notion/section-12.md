---
강의 수: 9
상태: 진행 중
섹션 번호: 12
섹션명: 섹션 12. 상속
완료일: null
완료한 강의 수: 3
중요도: ⭐⭐ OOP 핵심
진도율: 33
총 시간: 1시간 52분
---

# 섹션 12. 상속

## 📝 핵심 개념 정리
### 유도된 클래스들의 생성 순서
```cpp
#include <iostream>

using namespace std;

class Mother
{
public:
//private:
    int m_i;

public:
    Mother()
        : m_i(1)
    {
        cout << "Mother construction" << endl;
    }
};

class Child : public Mother
{
private:
    double m_d;

public:
    Child()
        :m_d(1.0)
    {
        cout << "Child construction" << endl;
    }
};

int main()
{
    Child c1;

    return 0;
}
```
Mother 생성자 후 Child 생성자.
public:<br>    Child()<br>        :m_d(1.0), Mother랑 다를게 없음. <br>Mother(1024) 이거 하려면<br>Mother(const int & i_in = 0)
	: m_i(i_in)<br>\{\}
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
- [ ] 복습 2회 (OOP 핵심 섹션은 2회 복습)
