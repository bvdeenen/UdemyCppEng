#include <array>
#include <cstdint>
#include <iostream>
#include <span>
#include <vector>

// void print_container(const std::vector<std::int32_t> &vec)
// {
//     for (const auto value : vec)
//     {
//         std::cout << value << '\n';
//     }
// }

// template<std::uint32_t N>
// void print_container(const std::array<std::int32_t, N> &arr)
// {
//     for (const auto value : arr)
//     {
//         std::cout << value << '\n';
//     }
// }

template<typename T>
void print_span(std::span<T> span)
{
    for (const T value : span)
    {
        std::cout << value << '\n';
    }
}

// class span:
// length/size of that contig. memory
// ptr to first element

int main()
{
    auto vec = std::vector<std::int32_t>{1, 2, 3};
    print_span<int32_t>(vec);

    std::array<long long, 3> arr = std::array{1LL, 2LL, 3LL};
    print_span<long long>(arr);

    return 0;
}
