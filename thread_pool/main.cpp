#include <iostream>
#include <chrono>
#include <random>
#include "handler.h"

void quicksort(RequestHandler& rh, int* array, long left, long right)
{
    if (left >= right)
        return;
    long left_bound = left;
    long right_bound = right;
    long middle = array[(left_bound + right_bound) / 2];
    do
    {
        while (array[left_bound] < middle)
        {
            left_bound++;
        }
        while (array[right_bound] > middle)
        {
            right_bound--;
        }
        if (left_bound <= right_bound)
        {
            std::swap(array[left_bound], array[right_bound]);
            left_bound++;
            right_bound--;
        }
    } while (left_bound <= right_bound);

    if (right_bound - left > 10000)
    {
        auto f = rh.push_task(quicksort, rh, array, left, right_bound); 
        quicksort(rh, array, left_bound, right);
        f.wait();
    }

    else
    {
        quicksort(rh, array, left, right_bound);
        quicksort(rh, array, left_bound, right);
    }
}


int main()
{
    RequestHandler rh;
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 100);
    size_t size{ 100000 };
    int* arr = new int[size];
    for(size_t i = 0; i < size; ++i)
    {
        arr[i] = dist(rd);
    }
    auto start = std::chrono::high_resolution_clock::now();
    quicksort(rh, arr, 0, size - 1);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> res = finish - start;
    std::cout << "result: " << res.count() << " sec" << std::endl;
    delete[] arr;
}
