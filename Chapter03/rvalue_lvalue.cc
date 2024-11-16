#include <iostream>
#include <numeric>
#include <vector>
#include <pstl/glue_numeric_defs.h>

// LValue: Left
// RValue: Right

void copy_by_value(int v) // input
{
    std::cout << v << std::endl;
}

void copy_by_value_const(const int v) // input
{
    std::cout << v << std::endl;
}

void reference(int &v) // in and output
{
    std::cout << v << std::endl;
}

void reference_const(const int &v) // input
{
    std::cout << v << std::endl;
}

void myswap(std::vector<int> &aa, std::vector<int>&bb ) noexcept {
    auto t = std::move(aa);
    aa = std::move(bb);
    bb = std::move(t);
}

int main()
{

    auto a = std::vector<int>{1,2,3};
    auto b = std::vector<int>{4,5,6};
    for(auto i =0; i< 1e6; i++) {
        a.push_back(rand());
        b.push_back(rand());
    }
    myswap(a, b);
    auto sum_a = std::accumulate(a.begin(), a.end(), 0LL);
    auto sum_b = std::accumulate(b.begin(), b.end(), 0LL);
    std::cout << sum_a << std::endl;
    std::cout << sum_b << std::endl;

    int lvalue = 2;
    const int lvalue_const = 2;

    copy_by_value(lvalue);
    copy_by_value(lvalue_const);
    copy_by_value(2);

    copy_by_value_const(lvalue);
    copy_by_value_const(lvalue_const);
    copy_by_value_const(2);

    reference(lvalue);
    // reference(lvalue_const);
    // reference(2);

    reference_const(lvalue);
    reference_const(lvalue_const);
    reference_const(2); // a temp. variable would be created

    return 0;
}
