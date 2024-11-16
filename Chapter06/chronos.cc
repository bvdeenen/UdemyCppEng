#include <chrono>
#include <cstdint>
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <format>

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

    const auto start_time = std::chrono::steady_clock::now();
    for (std::size_t i = 0; i < my_vector.size(); ++i)
    {
        my_vector[i] = dist(gen);
    }
    const auto end_time = std::chrono::steady_clock::now();

    const auto elapsed_time =
        std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "" << std::format("Elapsed time for generating {} randoms is {}", NUM_ELEMENTS, elapsed_time) << "\n";

    return 0;
}

/*
*
 any locations for breakpoint at /data4/Documents/development/cpp-2024/UdemyCppEng/Chapter06/chronos.cc:20,
 but found a valid location at /home/bvdeenen/Documents/development/cpp-2024/UdemyCppEng/Chapter06/chronos.cc:20
Launching: /data4/Documents/development/cpp-2024/UdemyCppEng/Chapter06/chronos.o
Launched process 54145
Process exited with code 0.
*
*/
