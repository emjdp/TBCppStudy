---
강의 수: 3
상태: 완료
섹션 번호: 17
섹션명: 섹션 17. 표준 템플릿 라이브러리 (STL)
완료일:
  end: null
  start: 2026-08-21
  time_zone: null
완료한 강의 수: 3
중요도: 기본
진도율: 100
총 시간: 40분
---

# 섹션 17. 표준 템플릿 라이브러리 (STL)

## 📝 핵심 개념 정리
### 컨테이너
```cpp
void sequence_containers()
{
    // vector
    {
        vector<int> vec; // #include <vector>
        for (int i = 0; i < 10; ++i)
            vec.push_back(i);

        for (auto& e : vec)
            cout << e << " ";
        cout << endl;
    }

    // deque
    {
        deque<int> deq; // #include <deque>
        for (int i = 0; i < 10; ++i)
        {
            deq.push_back(i);
            deq.push_front(i);
        }

        for (auto& e : deq)
            cout << e << " ";
        cout << endl;
    }
}

void associative_containers()
{
    // set
    {
        set<string> str_set;
        str_set.insert("Hello");
        str_set.insert("World");
        str_set.insert("Hello"); // 중복된 값은 무시됨
        cout << str_set.size() << endl; // 출력: 2
        for (auto& e : str_set)
            cout << e << " ";
        cout << endl;
    }
    // multiset
    {
        std::multiset<string> str_set;
        str_set.insert("Hello");
        str_set.insert("World");
        str_set.insert("Hello"); // 중복 허용
        cout << str_set.size() << endl; // 출력: 3
        for (auto& e : str_set)
            cout << e << " ";
        cout << endl;
    }
    // map : key / value 쌍 (Key 중복 불가)
    {
        std::map<char, int> map;
        map['a'] = 10;
        map['b'] = 20;
        map['c'] = 50;
        cout << map['a'] << endl; // 출력: 10
        map['a'] = 100; // 'a'의 value 수정
        cout << map['a'] << endl; // 출력: 100
        for (auto& e : map)
            cout << e.first << " " << e.second << " ";
        cout << endl;
    }
    // multimap : 중복된 키 허용
    {
        std::multimap<char, int> map;
        map.insert(std::pair('a', 10));
        map.insert(std::pair('b', 10));
        map.insert(std::pair('c', 10));
        map.insert(std::pair('a', 100)); // 같은 키 'a'로 또 추가 가능
        cout << map.count('a') << endl; // 'a' 키를 가진 원소 개수 출력: 2
        for (auto& e : map)
            cout << e.first << " " << e.second << " ";
        cout << endl;
    }
}

void container_adapters()
{
    // stack (LIFO: 후입선출)
    {
        cout << "Stack" << endl;

        std::stack<int> stack;
        stack.push(1);      // push adds a copy
        stack.emplace(2);   // emplace constructs a new object
        stack.emplace(3);
        cout << stack.top() << endl;
        stack.pop();
        cout << stack.top() << endl;
    }

    // queue (FIFO: 선입선출)
    {
        cout << "Queue" << endl;

        std::queue<int> queue;
        queue.push(1);
        queue.push(2);
        queue.push(3);
        cout << queue.front() << " " << queue.back() << endl;
        queue.pop();
        cout << queue.front() << " " << queue.back() << endl;
    }

    // Priority queue (우선순위 큐: 큰 값이 먼저 나옴)
    {
        cout << "Priority queue" << endl;

        std::priority_queue<int> queue;

        for (const int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
            queue.push(n);

        for (int i = 0; i < 10; ++i)
        {
            cout << queue.top() << endl;
            queue.pop();
        }
    }
}
```
### STL 반복자
```cpp
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

int main()
{
	vector<int> container; // list set map ...
	for (int i = 0; i < 10; ++i)
		container.push_back(i);

	vector<int>::const_iterator itr;
	itr = container.begin();
	while (itr != container.end())
	{
		cout << *itr << " ";

		++itr;
	}
	cout << endl;

	for (auto itr = container.begin(); itr != container.end(); ++itr)
		cout << *itr << " ";

	return 0;
}
```
### STL 알고리즘
```cpp
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main()
{
	using namespace std;

	vector<int> container;
	for (int i = 0; i < 10; ++i)
		container.push_back(i);

	//auto itr = li.begin();
	// list<int>::const_iterator itr;
	auto itr = min_element(container.begin(), container.end());
	cout << *itr << endl;

	itr = max_element(container.begin(), container.end());
	cout << *itr << endl;

	cout << endl;

	itr = find(container.begin(), container.end(), 3);
	container.insert(itr, 128);

	for (auto& e : container) cout << e << " ";
	cout << endl;

	sort(container.begin(), container.end());
	//li.sort();

	for (auto& e : container) cout << e << " ";
	cout << endl;

	reverse(container.begin(), container.end());
	//li.reverse();

	for (auto& e : container) cout << e << " ";
	cout << endl;

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
- [x] 강의 완주
- [x] 코드 직접 따라 침
- [ ] 복습 1회
