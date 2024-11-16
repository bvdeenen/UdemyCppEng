#include <cmath>
#include <complex>
#include <cstdint>
#include <format>
#include <iostream>
#include <limits>
#include <cxxabi.h>

template <typename T>
void print_type_properties()
{
    int status;
    auto realname = abi::__cxa_demangle(typeid(T).name(), NULL, NULL, &status);
    std::cout << std::format("----- {} ----\n", realname);
    std::cout << "min=" << std::numeric_limits<T>::min() << ", "
              << "max=" << std::numeric_limits<T>::max() << ", "
              << "bits=" << std::numeric_limits<T>::digits << ", "
              << "decdigits=" << std::numeric_limits<T>::digits10 << ", "
              << "integral=" << std::boolalpha
              << std::numeric_limits<T>::is_integer << ", "
              << "signed=" << std::boolalpha
              << std::numeric_limits<T>::is_signed << ", "
              << "exact=" << std::boolalpha << std::numeric_limits<T>::is_exact
              << ", "
              << "infinity=" << std::boolalpha
              << std::numeric_limits<T>::has_infinity << ", "
              << "quiet NaN=" << std::numeric_limits<T>::has_quiet_NaN << ", "
              << "€=" << std::numeric_limits<T>::epsilon() << ", "
              << '\n';
}

template <typename T>
bool equal(const T x, const T y)
{
    return x == y;
}

template <typename T>
bool almost_equal(const T x, const T y)
{
    return std::abs(x - y) <= std::numeric_limits<T>::epsilon();
}

int main()
{
    print_type_properties<std::uint16_t>();
    print_type_properties<std::int32_t>();
    print_type_properties<float>();
    print_type_properties<double>();
    print_type_properties<long long>();

    /*
    const auto d1 = 0.2;
    const auto d2 = 1.0 / (std::sqrt(5.0) * std::sqrt(5.0)); // == 1 / 5

    std::cout << d1 << '\n';
    std::cout << d2 << '\n';

    std::cout.precision(17);

    std::cout << d1 << '\n';
    std::cout << d2 << '\n';

    std::cout << "d1 == d2? " << std::boolalpha << equal(d1, d2) << '\n';

    std::cout << "epsilon = " << std::numeric_limits<float>::epsilon() << '\n';
    std::cout << "d1 ~= d2? " << std::boolalpha << almost_equal(d1, d2) << '\n';

*/
    return 0;
}
