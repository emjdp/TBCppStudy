---
강의 수: 8
상태: 완료
섹션 번호: 14
섹션명: 섹션 14. 템플릿
완료일:
  end: null
  start: 2026-08-18
  time_zone: null
완료한 강의 수: 8
중요도: ⭐ 중요
진도율: 100
총 시간: 1시간 10분
---

# 섹션 14. 템플릿

## 📝 핵심 개념 정리
### 함수 템플릿
```cpp
template<typename T>
T getMax(T x, T y)
{
    return (x > y) ? x : y;
}
```
```cpp
    std::cout << getMax(1, 2) << std::endl;
    std::cout << getMax(3.14, 1.592) << std::endl;
    std::cout << getMax(1.0f, 3.4f) << std::endl;
    std::cout << getMax('a', 'c') << std::endl;

    std::cout << getMax(Cents(5), Cents(9)) << std::endl;
```
템플릿으로 쓸수 있게 미리 준비해둬야 쓸 수 있음 ex)
```cpp
	Cents(int cents)
		: m_cents(cents)
	{
	}

	friend bool operator > (const Cents& c1, const Cents& c2)
	{
		return (c1.m_cents > c2.m_cents);
	}

	friend std::ostream& operator << (std::ostream & out, const Cents & cents)
	{
		out << cents.m_cents << " cents ";
		return out;
	}
```
### 클래스 템플릿
```cpp
template<typename T>
class MyArray
{
private:
    int m_length;
    T* m_data;

public:
    MyArray()
        : m_length(0), m_data(nullptr)
    { }

    MyArray(int length)
    {
        m_data = new T[length];
        m_length = length;
    }

    ~MyArray()
    {
        reset();
    }

    void reset()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    T& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int getLength() const { return m_length; }

    void print() const;
};
```
```cpp
int main()
{
    MyArray<int> my_array(10);
    for (int i = 0; i < my_array.getLength(); ++i)
        my_array[i] = i * 10;

    my_array.print();

    MyArray<char> char_array(5);
    // ...
}
```
템플릿 멤버 함수를 일반 클래스처럼 `.cpp`에 정의하면 컴파일러가 타입을 모른 채 넘어가서 링킹 에러(LNK2019)가 발생함.
```cpp
// MyArray.cpp
#include "MyArray.h"

template<typename T>
void MyArray<T>::print() const
{
    for (int i = 0; i < m_length; ++i)
        std::cout << m_data[i] << " ";
    std::cout << std::endl;
}

// 1. 함수 단위 명시적 인스턴스화 (const 꼭 맞춰줘야 함)
// template void MyArray<int>::print() const;

// 2. 클래스 전체 명시적 인스턴스화 (사용할 타입을 다 적어줘야 함)
template class MyArray<int>;
template class MyArray<double>;
template class MyArray<char>;
```
### 자료형이 아닌 템플릿 매개변수
```cpp
template<typename T, unsigned int T_SIZE>
class MyArray
{
private:
    //int m_length;
    T* m_data;

public:
    MyArray()
    {
        m_data = new T [T_SIZE];
    }

    ~MyArray()
    {
        delete[] m_data;
    }

    T& operator[](int index)
    {
        assert(index >= 0 && index < T_SIZE);
        return m_data[index];
    }

// ...
```
### 함수 템플릿 특수화
```cpp
template<typename T>
T getMax(T x, T y)
{
    return (x > y) ? x : y;
}

template<>
char getMax(char x, char y)
{
    cout << "Warnig : comparing chars" << endl;

    return (x > y) ? x : y;
}
```
### 클래스 템플릿 특수화
```cpp
template<typename T>
class A
{
public:
    void doSomething()
    {
        cout << typeid(T).name() << endl;
    }

    void test()
    { }
};

template<>
class A<char>
{
public:
    void doSomething()
    {
        cout << "Char type specialization" << endl;
    }
};
```
### 템플릿을 부분적으로 특수화하기
멤버 함수를 직접 특수화 하기 힘들 수 있으므로 상속 구조를 활용해 부분적으로 특수화
```cpp
template <class T, int size>
class StaticArray_BASE
{
private:
    T m_array[size];

public:
    T* getArray() { return m_array; }

    T& operator[](int index)
    {
        return m_array[index];
    }

    void print()
    {
        for (int count = 0; count < size; ++count)
            std::cout << (*this)[count] << ' ';
        std::cout << endl;
    }
};

template <class T, int size>
class StaticArray : public StaticArray_BASE<T, size>
{
};

template <int size>
class StaticArray<char, size> : public StaticArray_BASE<char, size>
{
public:
    void print()
    {
        for (int count = 0; count < size; ++count)
            std::cout << (*this)[count];
        std::cout << endl;
    }
};
```
### 포인터에 대한 템플릿 특수화
```cpp
template<class T>
class A
{
private:
    T m_value;

public:
    A(const T& input)
        : m_value(input)
    {
    }

    void print()
    {
        cout << m_value << endl;
    }
};

template<class T>
class A<T*>
{
private:
    T* m_value;

public:
    A(T * input)
        : m_value(input)
    {
    }

    void print()
    {
        cout << *m_value << endl;
    }
};
```
### 멤버 함수를 한 번 더 템플릿화 하기
```cpp
template<class T>
class A
{
private:
    T m_value;

public:
    A(const T& input)
        : m_value(input)
    {
    }

    template<typename TT>
    void doSomething()
    {
        cout << typeid(T).name() << " " << typeid(TT).name() << endl;
    }

    template<typename TTT>
    void doSomething2(const TTT & input)
    {
        cout << typeid(T).name() << " " << typeid(TTT).name() << endl;
        cout << (TTT)m_value << endl;
    }

    void print()
    {
        cout << m_value << endl;
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
- [ ] 복습 1회
