#include <iostream>
#include <memory>
#include <string>

class ScopeTest
{
public:
    ScopeTest(int val) : m_val(val)
    {
        std::cout << "Constructor: " << m_val << '\n';
    }

    ~ScopeTest()
    {
        std::cout << "Destructor:" << m_val << '\n';
    }

    void test()
    {
        std::cout << "Val: " << m_val << '\n';
    }

    std::weak_ptr<ScopeTest> m_partner;
    int m_val;
};

void f1()
{
    auto t = std::make_shared<ScopeTest>(1);
    t->test();

    std::cout << "Count: " << t.use_count() << '\n';

    {
        auto t2 = t;
        t2->test();

        std::cout << "Count: " << t.use_count() << '\n';
    }

    std::cout << "Count: " << t.use_count() << '\n';
}

void f2()
{
    auto t4 = std::make_shared<ScopeTest>(11);
    std::cout << "Count t4: " << t4.use_count() << '\n';
    auto t5 = std::make_shared<ScopeTest>(12);
    std::cout << "Count t5: " << t5.use_count() << '\n';

    t4->m_partner = t5;
    std::cout << "Count t5: " << t5.use_count() << '\n';
    t5->m_partner = t4;
    std::cout << "Count t4: " << t4.use_count() << '\n';
        auto t4_partner = t4->m_partner.lock();
    if (t4_partner != nullptr)
    {
        std::cout << "Count t4_partner: " << t4_partner.use_count() << '\n';
    }

}

int main()
{
    f1();
    std::cout << '\n';
    f2();

    return 0;
}
