---
강의 수: 22
상태: 진행 중
섹션 번호: 7
섹션명: 섹션 7. 행렬, 문자열, 포인터, 참조
완료일: null
완료한 강의 수: 2
중요도: ⭐ 중요
진도율: 9
총 시간: 4시간 48분
---

# 섹션 7. 행렬, 문자열, 포인터, 참조

## 📝 핵심 개념 정리
### 배열
    int my_array\[5\] = \{ 1,2,3,4,5 \};<br>    int my_array\[\] = \{ 1,2,3,4,5 \};<br>    int my_array\[\]\{ 1,2,3,4,5 \};<br>전부 동일.
int num_students = 0;<br>cin \>\> num_students;<br><br>// int students_scores\[num_students\]; // 런타임에서 사이즈가 고정된 곳에는 array를 사용할 수 없다<br>// 하고 싶으면 일단 cin 안하고 const int num_student = 5; 이런식으로 가능
```cpp
void doSomething(int student_scores[20]) // int student_scores[20] 이건 문법상 포인터. 배열이 아님
{
    cout << &student_scores << endl; // 포인터 변수의 주소가 나옴. 넘겨 받은 배열의 첫번째 주소값을 저장해둔 곳
    cout << &student_scores[0] << endl; // 이건 동일하게 나옴.
}

int main()
{
    const int num_students = 20;
    int student_scores[num_students] = {1, 2, 3, 4, 5, };

    cout << student_scores << endl; // 배열(식별자,인식자) 이름 자체가 주소로 사용되기 때문에 & 안붙여도 동일

    doSomething(student_scores); // 배열의 모든 원소를 통째로 가져오는게 아니라 첫번째 주소값만 복사
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
- [ ] 강의 완주
- [ ] 코드 직접 따라 침
- [ ] 복습 1회
