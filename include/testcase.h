#ifndef TESTCASE_H
#define TESTCASE_H

#include <future>

class TestCase {
public:
    TestCase();
    virtual ~TestCase() = default;

    bool Run();
    void RunAsync();
    bool Report();

protected:
    virtual bool Test() = 0;

private:
    std::future<bool> data_;
    uint32_t id_ = 0;
};

#endif // TESTCASE_H
