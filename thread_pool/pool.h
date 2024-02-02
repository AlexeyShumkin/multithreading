#pragma once
#include <vector>
#include <thread>
#include <functional>
#include <future>
#include <memory>
#include "blockedQueue.h"

using task_type = std::function<void()>;
using FuncType = void (*) (int*, long, long);

class ThreadPool
{
public:
    ThreadPool();
    void start();
    void stop();
    std::future<void> push_task(FuncType f, int* arr, long arg1, long arg2);
    void threadFunc(int qindex);
private:
    int m_thread_count{ 0 };
    std::vector<std::thread> m_threads;
    std::vector<BlockedQueue<task_type>> m_thread_queues;
    int m_index{ 0 };
};
