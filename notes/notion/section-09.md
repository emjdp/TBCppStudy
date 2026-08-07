---
강의 수: 15
상태: 진행 중
섹션 번호: 9
섹션명: 섹션 9. 객체지향의 기초
완료일: null
완료한 강의 수: 1
중요도: ⭐⭐ OOP 핵심
진도율: 7
총 시간: 3시간 16분
---

# 섹션 9. 객체지향의 기초

## 📝 핵심 개념 정리
**다음 학기 수업의 심장부.** 클래스, 생성자/소멸자, 접근 지정자, this 포인터 등을 남에게 설명할 수 있을 정도로 정리
### 객체지향 프로그래밍과 클래스
```cpp
class Friend
{
public: // access specifier (public, private, protected)
    string name;
    string address;
    int age;
    double height;
    double weight;

    void print()
    {
        cout << name << " " << address << " " << age << " " << height << " " << weight << endl;
    }
};

int main()
{

    Friend jj("Jack Jack", "Uptown", 2,30, 10); // instanciation, instance
    /*
    print(jj.name, jj.address, jj.age, jj.height, jj.weight);
    print(jj);
    */

    jj.print();

    vector<Friend> my_friends;
    my_friends.resize(2);

    //my_friends[0].print();
    //my_friends[1].print();
    for (auto& ele : my_friends)
        ele.print();

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
- [ ] 복습 2회 (OOP 핵심 섹션은 2회 복습)
