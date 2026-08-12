---
강의 수: 12
상태: 완료
섹션 번호: 10
섹션명: 섹션 10. 연산자 오버로딩
완료일:
  end: null
  start: 2026-08-12
  time_zone: null
완료한 강의 수: 12
중요도: ⭐⭐ OOP 핵심
진도율: 100
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
```cpp
class IntList
{
private:
	int m_list[10];
	//int m_list[10] = { 1,2,3,4,5,6,7,8,9,10 };
public:
	int& operator [] (const int index)
	{
		return m_list[index];
	}

/*
	const int& operator [] (const int index) const
	{
		return m_list[index];
	}
*/
};
```
```cpp
	//주의
	IntList2* list = new IntList2;

	//list[3] = 10; // not OK
	(*list)[3] = 10; // OK
```
### 괄호 연산자 오버로딩
```cpp
class Accumulator
{
private:
    int m_counter = 0;

public:
    int operator()(int i) { return (m_counter += i); }
};
```
### 형변환 오버로딩
```cpp
class Cents
{
private:
    int m_cents;

public:
    Cents(int cents = 0)
    {
        m_cents = cents;
    }

    int getCents() { return m_cents; }
    void setCents(int cents) { m_cents = cents; }

    operator int()
    {
        cout << "cast here" << endl;
        return m_cents;
    }
};

class Dollar
{
private:
    int m_dollars = 0;

public:
    Dollar(const int& input) : m_dollars(input) {}

    operator Cents()
    {
        return (m_dollars * 100);
    }
};
```
### 복사 생성자, 복사 초기화, RVO(Return Value Optimization)
```cpp
class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(int num = 0, int den = 1)
        : m_numerator(num), m_denominator(den)
    {
        assert(den != 0);
    }

    Fraction(const Fraction& fraction) // copy constructor
        : m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
    {
        cout << "Copy constructor called" << endl;
    }

    friend std::ostream& operator << (std::ostream& out, const Fraction& f)
    {
        out << f.m_numerator << " / " << f.m_denominator << endl;
        return out;
    }
};
```
```cpp
    Fraction frac(3, 5);

    Fraction fr_copy(frac);
    //Fraction fr_copy = frac;

    cout << frac << " " << fr_copy << endl;
```
```cpp
Fraction doSomething()
{
    Fraction temp(1, 2);
    cout << &temp << endl;
    return temp;
}
```
```cpp
    Fraction result = doSomething();
    cout << &result << endl;
    cout << result << endl;
```
이렇게 하면 result랑 temp 주소가 같음. 컴파일러에서 RVO로 그냥 변환 함
### 변환 생산자, explicit, delete
```cpp
class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(char) = delete;

    explicit Fraction(int num = 0, int den = 1)
        : m_numerator(num), m_denominator(den)
    {
        assert(den != 0);
    }

    Fraction(const Fraction& fraction) // copy constructor
        : m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
    {
        cout << "Copy constructor called" << endl;
    }

    friend std::ostream& operator << (std::ostream& out, const Fraction& f)
    {
        out << f.m_numerator << " / " << f.m_denominator << endl;
        return out;
    }
};

void doSomething(Fraction frac)
{
    cout << frac << endl;
}
```
```cpp
int main()
{
    Fraction frac(7);
    // Fraction frac('c'); // delete으로 막힘
    // doSomething(7); //explicit으로 막힘
    return 0;
}
```
### 대입 연산자 오버로딩, 깊은 복사, 얕은 복사
- **얕은 복사**: 포인터의 주소만 복사한다.
- **깊은 복사**: 새로운 메모리를 할당하고 실제 값까지 복사한다.
- 디폴트 복사 생성자는 얕은 복사를 하므로, 동적 메모리를 사용하면 두 객체가 같은 메모리를 가리킨다.
- 이 경우 한 객체가 메모리를 해제하면 다른 객체의 포인터가 무효가 되며, **중복 해제 ** 문제가 생길 수 있다.
```cpp
MyString& operator=(const MyString& source)
{
    if (this == &source) return *this; // 자기 대입 방지

    delete[] m_data;
    // 새 메모리 할당 후 내용 복사
    return *this;
}
```
> 동적 메모리를 직접 관리하는 클래스는 복사 생성자, 대입 연산자, 소멸자를 함께 구현해야 한다.
### 이니셜라이져 리스트 오버로딩
```cpp
class IntArray
{
private:
    unsigned m_length = 0;
    int* m_data = nullptr;

public:
    IntArray(unsigned length)
        : m_length(length)
    {
        m_data = new int[length];
    }

    IntArray(const std::initializer_list<int>& list)
        : IntArray(list.size())
    {
        int count = 0;
        for (auto& element : list)
        {
            m_data[count] = element;
            ++count;
        }

    }

    ~IntArray()
    {
        delete[] this->m_data;
    }

    friend ostream& operator << (ostream& out, IntArray& arr)
    {
        for (unsigned i = 0; i < arr.m_length; ++i)
            out << arr.m_data[i] << " ";
        out << endl;
        return out;
    }

};
```
## 💻 코드 스니펫
```cpp
// 직접 따라 친 코드 중 기억할 것
```
## 🔥 헷갈린 것들 / 질문
-
## ✅ 복습 체크
- [x] 강의 완주
- [x] 코드 직접 따라 침
- [x] 복습 1회
- [ ] 복습 2회 (OOP 핵심 섹션은 2회 복습)
