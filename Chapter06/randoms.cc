#include <cstdint>
#include <iostream>
#include <random>
#include <vector>

namespace
{
constexpr auto NUM_ELEMENTS = size_t{1'000'000U};
};

int main()
{
    auto my_vector = std::vector<std::int32_t>(NUM_ELEMENTS, 0U);

    std::random_device seed;
    auto gen = std::mt19937{seed()};
    auto dist = std::uniform_int_distribution<std::int32_t>{-10, 10};

    for (auto &val : my_vector)
    {
        val = dist(gen);
    }

    for (std::size_t i = 0; i < 10; ++i)
    {
        std::cout << my_vector[i] << '\n';
    }

    return 0;
}
