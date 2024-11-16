#pragma once
#include <cstdint>
#include <iterator>
#include <vector>

namespace mystd
{

using It = std::vector<std::int32_t>::iterator;
using DifferenceType = It::difference_type;

    It next(It it);
    It prev(It it);
    void advance(It &it, DifferenceType n);
    DifferenceType distance(It first, It last) ;
} // namespace mystd
