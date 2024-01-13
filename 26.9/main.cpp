#include "wrapper.h"

int main()
{
    size_t size = 1000000;
    Wrapper wr(size, 0, 100);
    auto start = std::chrono::system_clock::now();
    wr.mergeSort(0, size - 1);
    auto finish = std::chrono::system_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
    std::cout << diff << " ms\n";
    // start = std::chrono::system_clock::now();
    // res = wr.singleThreadSum();
    // finish = std::chrono::system_clock::now();
    // diff = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
    // std::cout << "sum without multithreading: " << res << '\t' << diff << " ms\n";
}