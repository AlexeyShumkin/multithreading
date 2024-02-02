#include <iostream>
#include <chrono>
#include <random>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include "handler.h"

bool make_thread{ false };

void quicksort(int* array, long left, long right)
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
    if (make_thread && right_bound - left > 10000)
    {
        static RequestHandler rh;
        auto f = rh.push_task(quicksort, array, left, right_bound); 
        quicksort(array, left_bound, right);
        f.wait();
    }
    else
    {
        quicksort(array, left, right_bound);
        quicksort(array, left_bound, right);
    }
}

void doSpecSort(FuncType f, int* arr, long left, long right, std::filesystem::path path)
{
    auto start = std::chrono::high_resolution_clock::now();
    f(arr, left, right - 1);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> res = finish - start;
    std::cout << "1) sorting time: "<< std::fixed << std::setprecision(3) << res.count() << " seconds" << std::endl;
    std::ofstream out(path);
    for(size_t i = 0; i < right; ++i)
    {
        out << arr[i];
    }
    out.close();
    std::cout << "2) file size: " << std::filesystem::file_size(path) << " bytes" << std::endl;
}

int main()
{
    size_t size{ 100000 };
    int* arr1 = new int[size];
    int* arr2 = new int[size];
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 9);
    for(size_t i = 0; i < size; ++i)
    {
        arr1[i] = dist(rd);
        arr2[i] = arr1[i];
    }
    std::filesystem::path path1 = "sort_test_1";
    std::cout << "Single thread sorting results: \n";
    doSpecSort(quicksort, arr1, 0, size, path1);
    make_thread = true;
    std::cout << "\nSorting with thread pool results: \n";
    std::filesystem::path path2 = "sort_test_2";
    doSpecSort(quicksort, arr2, 0, size, path2);
    delete[] arr1;
    delete[] arr2;
}
