#pragma once
#include <vector>
#include <random>
#include <iostream>
#include <thread>
#include <chrono>

class Wrapper
{
public:
    Wrapper(int n, int m, int left, int right);
    int multiThreadSum();
    int singleThreadSum();
    void show();
private:
    void sum(int i, int j);
    int size_{ 0 };
    std::vector<int> nums_;
    int numOfThreads_{ 0 };
    int result_{ 0 };
};
