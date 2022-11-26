#ifndef TESTCASE_H
#define TESTCASE_H

#include <future>

class TestCase {
public:
    TestCase() = default;
    virtual ~TestCase() = default;

    bool Run();
    void RunAsync();
    bool Report();

protected:
    virtual bool Test() = 0;

private:
    std::future<bool> data_;
};

#endif // TESTCASE_H
