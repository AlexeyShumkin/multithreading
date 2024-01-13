#include <iostream>
#include <chrono>
#include <future>
#include <vector>

using matrix = std::vector<std::vector<int>>;

void correct(matrix& m1, matrix& m2)
{
    auto col1 = m1.front().size();
    auto str2 = m2.size();
    if(col1 > str2)
    {
        for(size_t i = str2; i < col1; ++i)
        {
            std::vector<int> str;
            for(size_t j = 0; j <= col1 - str2; ++j)
            {
                str.push_back(1);
            }
            m2.push_back(str);
        }
    }
    else if(str2 > col1)
    {
        for(auto& m : m1)
        {
            for(size_t i = m.size(); i < str2; ++i)
            {
                m.push_back(1);
            }
        }
    }
}

void show(matrix& matrix)
{
    for(auto& str : matrix)
    {
        for(auto& num : str)
        {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    }
}

matrix multiply(matrix& matrix1, matrix& matrix2)
{
    auto col1 = matrix1.front().size();
    auto commonSize = matrix2.size();
    if(col1 != commonSize)
    {
        correct(matrix1, matrix2);
    }
    int resLines = matrix1.size();
    int resCollums = matrix2.front().size();
    matrix result(resLines);
    for (int i = 0; i < resLines; ++i) 
    {
        result[i].resize(resCollums);
    }
    std::vector<std::future<void>> futures;
    for (int i = 0; i < resLines; ++i) 
    {
        auto f = std::async(std::launch::async, [&, i]() {
            for (int j = 0; j < resCollums; ++j) 
            {
                int cell_result = 0;
                for (int k = 0;k < commonSize; ++k) 
                {
                    cell_result += matrix1[i][k] * matrix2[k][j];
                }
                result[i][j] = cell_result;
            }
        });
        futures.push_back(std::move(f));
    }
    return result;
}

int main()
{
    std::vector<int> s1{1, 2};
    std::vector<int> s2{3, 1};
    std::vector<int> s3{4, 6};
    std::vector<int> s4{3, 5};
    std::vector<int> s5{2, 8};

    std::vector<int> v1{4, 2, 3, 5, 6, 1, 7};
    std::vector<int> v2{3, 1, 2, 5, 9, 3, 4};
    std::vector<int> v3{3, 1, 2, 5, 9, 3, 4};

    matrix m1{s1, s2, s3, s4, s5};
    matrix m2{v1, v2, v3};
    auto start = std::chrono::system_clock::now();
    matrix m3 = multiply(m1, m2);
    auto finish = std::chrono::system_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
    std::cout << diff << " ms\n";
    show(m3);
}
