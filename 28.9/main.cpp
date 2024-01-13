#include "../26.9/wrapper.h"

int main()
{
    size_t size = 10000000;
    Wrapper wr(size, 0, 1000);
    auto start = std::chrono::system_clock::now();
    wr.mergeSort(0, size - 1);
    auto finish = std::chrono::system_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
    std::cout << diff << " ms\n";
}