#include "wrapper.h"

int main()
{
    Wrapper wr(10000001, 4, 0, 10);
    auto start = std::chrono::system_clock::now();
    auto res = wr.multiThreadSum();
    auto finish = std::chrono::system_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
    std::cout << "sum using multithreading: " << res << '\t' << diff << " ms\n";

    start = std::chrono::system_clock::now();
    res = wr.singleThreadSum();
    finish = std::chrono::system_clock::now();
    diff = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
    std::cout << "sum without multithreading: " << res << '\t' << diff << " ms\n";
}