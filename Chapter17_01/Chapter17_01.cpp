// Chapter17_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>

using namespace std;

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

int main()
{
    //sequence_containers();
    //associative_containers();
    //container_adapters();
    return 0;
}