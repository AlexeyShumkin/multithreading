#include "../26.9/wrapper.h"

Wrapper::Wrapper(int n, int left, int right) : size_(n) 
{
    std::random_device rd;
    std::uniform_int_distribution<int> dist(left, right);
    nums_.resize(size_);
    for(int i = 0; i < size_; ++i)
    {
        nums_[i] = dist(rd);
    }
}

void Wrapper::merge(size_t beg, size_t mid, size_t end)
{
    auto lsize = mid - beg + 1;
    auto rsize = end - mid;
    std::vector<int> left(lsize);
    std::vector<int> right(rsize);
    for (size_t i = 0; i < lsize; ++i)
    {
        left[i] = nums_[beg + i];
    }
    for (size_t j = 0; j < rsize; ++j)
    {
        right[j] = nums_[mid + 1 + j];
    }
    size_t i = 0, j = 0, index = beg;
    while (i < lsize && j < rsize) 
    {
        if (left[i] <= right[j]) 
        {
            nums_[index++] = left[i++];
        }
        else 
        {
            nums_[index++] = right[j++];
        }
    }
    while (i < lsize) 
    {
        nums_[index++] = left[i++];
    }
    while (j < rsize) 
    {
        nums_[index++] = right[j++];
    }
}

void Wrapper::mergeSort(size_t beg, size_t end, uint threadCount)
{
    if(beg >= end) return;
    size_t mid = (beg + end) / 2;
    static const uint maxThreads = std::thread::hardware_concurrency();
    if(threadCount < maxThreads)
    {
        auto f = std::async(std::launch::async, [&]() {
            mergeSort(beg, mid, threadCount * 2);
        });
        mergeSort(mid + 1, end, threadCount * 2);
        f.wait();
    }
    else
    {
        mergeSort(beg, mid, threadCount);
        mergeSort(mid + 1, end, threadCount);
    }
    merge(beg, mid, end);
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

int Wrapper::multiThreadSum(int m)
{
    std::vector<std::thread> threads;
    auto range = size_/m;
    result_ = 0;
    int left = 0;
    int right = 0;
    for (int i = 0, j = 1; i < m; ++i, ++j)
    {
        left = i * range;
        if (i != m - 1)
            right = j * range;
        else
            right = size_;
        std::thread t(&Wrapper::sum, this, left, right);
        threads.push_back(std::move(t));
    }
    for (int i = 0; i < m; ++i)
    {
        threads[i].join();
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