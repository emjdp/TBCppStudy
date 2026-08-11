---
강의 수: 12
상태: 진행 중
섹션 번호: 10
섹션명: 섹션 10. 연산자 오버로딩
완료일: null
완료한 강의 수: 5
중요도: ⭐⭐ OOP 핵심
진도율: 42
총 시간: 1시간 38분
---

# 섹션 10. 연산자 오버로딩

## 📝 핵심 개념 정리
### 산술 연산자 오버로딩 하기
```cpp
Cents add(const Cents& c1, const Cents& c2)
{
    return Cents(c1.getCents() + c2.getCents());
}
```
이걸 오버로딩으로 구현하면
```cpp
Cents operator + (const Cents& c1, const Cents& c2)
{
    return Cents(c1.getCents() + c2.getCents());
}
```
함수 내에서 하려면
```cpp
class Cents
{
private:
    int m_cents;

public:
    Cents(int cents = 0) { m_cents = cents; }
    int getCents() const { return m_cents; }
    int& getCents() { return m_cents; }

    /*
    friend Cents operator + (const Cents& c1, const Cents& c2)
    {
        return Cents(c1.getCents() + c2.getCents());
    }
    */

    Cents operator + (const Cents& c2)
    {
        return Cents(this->m_cents + c2.m_cents);
    }
};
```
=, \[\], (), → 이거는 멤버 function으로만 구현 가능함
### 입출력 연산자 오버로딩
```cpp
    friend std::ostream& operator << (std::ostream& out, const Point& point)
    {
        out << point.m_x << " " << point.m_y << " " << point.m_z;

        return out;
    }

    friend std::istream& operator >> (std::istream& in, Point& point)
    {
        in >> point.m_x >> point.m_y >> point.m_z;

        return in;
    }
```
### 단항 연산자 오버로딩
```cpp
    Cents operator - () const
    {
        return Cents(-m_cents);
    }

    bool operator ! () const
    {
        return (m_cents == 0) ? true : false;
    }
```
### 비교 연산자 오버로딩
```cpp
    friend bool operator == (const Cents& c1, const Cents& c2)
    {
        return c1.m_cents == c2.m_cents;
    }

    friend bool operator < (const Cents& c1, const Cents& c2)
    {
        return c1.m_cents < c2.m_cents;
    }
```
### 증감 연산자 오버로딩
```cpp
    //prefix
    Digit& operator ++ ()
    {
        ++m_digit;
        return *this;
    }

    //postfix
    Digit operator ++ (int)
    {
        Digit temp(m_digit);
        ++(*this);

        return temp;
    }
```
### 첨자 연산자 오버로딩
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
