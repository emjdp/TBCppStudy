// Chapter20_03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

using namespace std;

std::mutex mtx; // 상호 배제를 위한 mutex 객체 선언

int main()
{
/*    cout << std::thread::hardware_concurrency() << endl;
    cout << std::this_thread::get_id() << endl;

    const int num_pro = std::thread::hardware_concurrency();

    vector<std::thread> my_threads;
    my_threads.resize(num_pro);

    for (auto& e : my_threads)
        e = std::thread([]() {
        cout << std::this_thread::get_id() << endl;
        while (true) {}});

    for (auto& e : my_threads)
        e.join();*/

    /*auto work_func = [](const string & name)
    {
        for (int i = 0; i < 5; ++i)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));

            cout << name << " " << std::this_thread::get_id() << " is working " << i << endl;
        }
    };

    work_func("JackJack");
    work_func("Dash");*/

    // 멀티스레딩
    auto work_func = [](const string & name)
    {
        for (int i = 0; i < 5; ++i)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));

            mtx.lock();
            cout << name << " " << std::this_thread::get_id() << " is working " << i << endl;
            mtx.unlock();
        }
    };

    std::thread t1 = std::thread(work_func, "JackJack");
    std::thread t2 = std::thread(work_func, "Dash");

    t1.join();
    t2.join();

    return 0;
}
