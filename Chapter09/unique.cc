#include <format>
#include <iostream>
#include <memory>

class ScopeTest
{
public:
    ScopeTest(int val) : m_val(val)
    {
        std::cout << "Constructor: " << m_val << '\n';
    }

    ~ScopeTest()
    {
        std::cout << std::format("Destructor ! {}\n", m_val);
    }

    void test()
    {
        std::cout << std::format("Test ! {}\n", m_val);
    }

private:
    int m_val;
};

void f3(std::unique_ptr<ScopeTest> t) {
    t->test() ;
}

void f1()
{
    auto t = std::make_unique<ScopeTest>(10);
    t->test();
}

void f2()
{
    auto *t2 = new ScopeTest(20);
    t2->test();
    delete t2;
}

int main()
{
    f1();
    std::cout << '\n';
    f2();

    return 0;
}
