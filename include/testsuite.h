#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <vector>
#include <memory>

#include <testcase.h>

enum class RunType { Sync, Async };

class TestSuite {
public:
    TestSuite() = default;
    virtual ~TestSuite() = default;

    void AddTestCase(std::shared_ptr<TestCase> testcase);
    bool RunTestCase(std::shared_ptr<TestCase> testcase);
    bool RunTestCase(int index);
    bool RunAllTestCase(RunType type = RunType::Sync);

    std::size_t GetSize();

private:
    using TestCases = std::vector<std::shared_ptr<TestCase>>;
    TestCases testcases_;
};

#endif // TESTSUITE_H
