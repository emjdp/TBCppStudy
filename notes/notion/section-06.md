---
강의 수: 10
상태: 진행 중
섹션 번호: 6
섹션명: 섹션 6. 흐름 제어
완료일: null
완료한 강의 수: 3
중요도: 기본
진도율: 30
총 시간: 2시간 30분
---

# 섹션 6. 흐름 제어

## 📝 핵심 개념 정리
```cpp
    #include <cstdlib>
    exit(0); // 무조건 종료해야 할 때
```
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
## 🔥 헷갈린 것들 / 질문
- switch-case `Fallthrough`  하면 IDE에서 경고 밑줄 뜨는  것은 어떻게 해결?<br>→ c++17부터 `[[fallthrough]];`로 속성 추가 가능
## ✅ 복습 체크
- [ ] 강의 완주
- [ ] 코드 직접 따라 침
- [ ] 복습 1회
