//
// Created by bvdeenen on 7-11-24.
//
#include "IteratorLib.h"
namespace mystd {

    void advance(It &it, int64_t n) {
        if(n>0) {
            while(--n ) ++it;
        }
        if(n<0) {
            while(++n ) --it;
        }
    }
    DifferenceType distance(It first, It last) {
        auto result = DifferenceType{ 0 };
        while(first!=last) {
            ++first;
            ++result;
        }
        return result;
    }

    It next(It it) {
        advance(it,1);
        return it;
    }

    It prev(It it);
}
