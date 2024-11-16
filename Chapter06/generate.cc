#include <algorithm>
#include <cstdint>
#include <iostream>
#include <random>
#include <vector>

namespace
{
constexpr auto NUM_ELEMENTS = size_t{100};
};

std::int64_t gen()
{
    static auto i = 1LL;
    return i *=2, i;
}

template <typename T>
void print_vector(const std::vector<T> &vec)
{
    for (const auto val : vec)
    {
        std::cout << val << '\n';
    }
    std::cout << '\n';
}

int main()
{
    auto my_vector = std::vector<std::int64_t>(NUM_ELEMENTS, 0U);
    std::generate(my_vector.begin(), my_vector.end(), gen);
    print_vector(my_vector);

    return 0;
}
