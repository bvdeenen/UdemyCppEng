#include <cstdint>
#include <iterator>
#include <vector>

namespace mystd
{

using It = std::vector<std::int32_t>::iterator;
using DifferenceType = It::difference_type;

inline void advance(It &it, DifferenceType n)
{
    while (n > 0)
    {
        ++it;
        --n;
    }

    while (n < 0)
    {
        --it;
        ++n;
    }
}

inline DifferenceType distance(It first, It last)
{
    auto result = DifferenceType{0};

    while (first != last)
    {
        ++first;
        ++result;
    }

    return result;
}

inline It next(It it, DifferenceType n = 1)
{
    mystd::advance(it, n);
    return it;
}

inline It prev(It it, DifferenceType n = 1)
{
    mystd::advance(it, -n);
    return it;
}

} // namespace mystd
