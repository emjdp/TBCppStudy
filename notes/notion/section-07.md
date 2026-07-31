---
강의 수: 22
상태: 진행 중
섹션 번호: 7
섹션명: 섹션 7. 행렬, 문자열, 포인터, 참조
완료일: null
완료한 강의 수: 9
중요도: ⭐ 중요
진도율: 41
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
포인터는 왜 쓸까?
	→ 1. array에서 첫 번째 주소랑 데이터 몇개가 있다 정도를 알려주면 효율적임
	1. 변수를 자체로 여기저기서 쓸때 매번 변수 전체를 복사할 필요가 없어짐
```cpp
int main()
{
    int x = 5;
    double d = 123.0;

    int* ptr_x = &x, * ptr_y = &x;
    double* ptr_d = &d;

    cout << sizeof(x) << endl;  // 4
    cout << sizeof(d) << endl;  // 8
    cout << sizeof(&x) << " " << sizeof(ptr_x) << endl; // 8 8
    cout << sizeof(&d) << " " << sizeof(ptr_d) << endl; // 8 8
```
집이 크다고 해서 주소가 길지는 않다.
널 포인터(null pointer)
```cpp
    double *ptr = 0; // c-style
    double* ptr = NULL; // c-style
    double* ptr = nullptr; // mpdern c++
    double* ptr{ nullptr }; // mpdern c++
```
```cpp
if (ptr != nullptr)
{
    //do something useful
    std::cout << *ptr << std::endl;
}
else
{
    //do nothing with ptr
    std::cout << "NULL ptr, do nothing" << std::endl;
}
```
```cpp
std::nullptr_t nptr; //nullptr 값만 넣을 수 있음
```
---
```cpp
void printArray(int array[]) // int *array 같음
{
    cout << sizeof(array) << endl;
    *array = 100; // 함수 밖에서도 바뀜
}
```
```cpp
int main()
{

    int array[5] = { 9,7,5,3,1 };

    cout << array << endl;
    cout << &array[0] << endl; // array 랑 같음. array는 사실상 포인터

    int *ptr = array;
    cout << "size : " << sizeof(ptr) << endl;
    cout << ptr << endl;
    cout << *ptr << endl;

    printArray(array); // 20아니고 8나옴. 함수 안에서도 내부적으로는 포인터.
    cout << *array << endl;

    return 0;
}
```
main 밖 함수에서 \*array를 수정하였기 때문에 메인의 array\[0\] 바뀜. 배열 시작점 메모리에 접근해서 변경.
## 💻 코드 스니펫
```cpp
for (int i = 0; i < num_students; ++i)
{
    total_score += scores[i];
    //if (max_score < scores[i]) max_score = scores[i];
    max_score = (max_score < scores[i]) ? scores[i] : max_score;
}
```
```cpp
    int array[num_rows][num_coloums] = // row-major <-> column-major
    {
        {1,2,3,4,5}, //row 0
        {6,7,8,9,10}, //row 1
        {11,12,13,14,15} //row2
    };


    for (int row = 0; row < num_rows; ++row)
    {
        for (int col = 0; col < num_coloums; ++col)
            //cout << array[row][col] << '\t';
            cout << (int) & array[row][col] << '\t';

        cout << endl;

    }
```
```cpp
    char myString[] = "string"; // 문자열 맨 마지막에 null character(\0)가 있어서 7글자

    for (int i = 0; i < 7; ++i)
    {
        cout << (int)myString[i] << endl;
    }
    cout << sizeof(myString) / sizeof(myString)[0] << endl;

    char uString[255];
    //cin >> uString;
    cin.getline(uString, 255);
    //uString[4] = '\0'; // 4번 인덱스 부터 뒤로 생략
    cout << uString << endl;

    int ix = 0;
    while (true)
    {
        if (uString[ix] == '\0') break;

        cout << uString[ix] << " " << (int)myString[ix] << endl;
        ++ix;
    }

```
## 🔥 헷갈린 것들 / 질문
- cout \<\< '\[' \<\< row \<\< '\]' \<\< '\[' \<\< col \<\< ' \]' \<\< '\\t';
 ' \['는 공백(0x20)과 \](0x5D)라는 두 문자의 아스키 코드가 합쳐진 0x205D 라는 16진수 정수가 됨 <br>한참 찾았네.. 실수 주의.
## ✅ 복습 체크
- [ ] 강의 완주
- [ ] 코드 직접 따라 침
- [ ] 복습 1회
