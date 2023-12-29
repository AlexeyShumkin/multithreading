#include "wrapper.h"

Wrapper::Wrapper(int n, int m, int left, int right) : size_(n), numOfThreads_(m) 
{
    std::random_device rd;
    std::uniform_int_distribution<int> dist(left, right);
    nums_.resize(size_);
    for(int i = 0; i < size_; ++i)
    {
        nums_[i] = dist(rd);
    }
}

void Wrapper::sum(int i, int j)
{
    int tmp = 0;
    while (i < j)
    {
        tmp += nums_[i++];
    }
    result_ += tmp;
} 

int Wrapper::multiThreadSum()
{
    std::vector<std::thread> threads;
    auto range = size_/numOfThreads_;
    result_ = 0;
    int left = 0;
    int right = 0;
    for(int i = 0, j = 1; i < numOfThreads_; ++i, ++j)
    {
        left = i * range;
        if(i != numOfThreads_ - 1)
            right = j * range;
        else
            right = size_;
        std::thread t(&Wrapper::sum, this, left, right);
        threads.push_back(std::move(t));
    }
    for (auto& t: threads)
    {
        t.join();
    }
    return result_;
}

int Wrapper::singleThreadSum()
{
    result_ = 0;
    for (int i = 0; i < size_; i++)
    {
        result_ += nums_[i];
    }
    return result_;
}

void Wrapper::show()
{
    std::cout << "nums: ";
    for(const auto& num : nums_)
    {
        std::cout << num << ' ';
    }
    std::cout << std::endl;
}
