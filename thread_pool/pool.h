#pragma once
#include <vector>
#include <thread>
#include <functional>
#include <future>
#include <memory>
#include "blockedQueue.h"

class RequestHandler;

typedef std::function<void()> task_type;
typedef void (*FuncType) (RequestHandler&, int*, long, long);
typedef std::future<void> res_type;

class ThreadPool
{
public:
    ThreadPool();
    void start();
    void stop();
    res_type push_task(FuncType f, RequestHandler& rh, int* arr, long arg1, long arg2);
    void threadFunc(int qindex);
private:
    struct PromiseTask
    {
        task_type task;
        std::promise<void> prom;
    };
    int m_thread_count{};
    std::vector<std::thread> m_threads;
    std::vector<BlockedQueue<PromiseTask>> m_thread_queues;
    int m_index{};
};
