#pragma once
#include <vector>
#include <random>
#include <iostream>
#include <thread>
#include <future>
#include <chrono>

class Wrapper
{
public:
    Wrapper(int n, int left, int right);
    int multiThreadSum(int m);
    int singleThreadSum();
    void mergeSort(size_t beg, size_t end, uint threadCount = 1);
    void show();
private:
    void merge(size_t beg, size_t mid, size_t end);
    void sum(int i, int j);
    size_t size_{ 0 };
    std::vector<int> nums_;
    int result_{ 0 };
};
