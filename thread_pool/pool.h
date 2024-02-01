#pragma once
#include <vector>
#include <thread>
#include <functional>
#include <future>
#include <memory>
#include "blockedQueue.h"

class RequestHandler;

using task_type = std::function<void()>;
using FuncType = void (*) (RequestHandler&, int*, long, long);
using res_type = std::future<void>;

struct PromiseTask
{
    task_type task;
    std::promise<void> prom;
};

class ThreadPool
{
public:
    ThreadPool();
    void start();
    void stop();
    res_type push_task(FuncType f, RequestHandler& rh, int* arr, long arg1, long arg2);
    void threadFunc(int qindex);
private:
    int m_thread_count{ 0 };
    std::vector<std::thread> m_threads;
    std::vector<BlockedQueue<PromiseTask>> m_thread_queues;
    int m_index{ 0 };
};
