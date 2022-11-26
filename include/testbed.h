#ifndef TESTBED_H
#define TESTBED_H

#include <vector>
#include <memory>

#include <testcase.h>

enum class RunType { Sync, Async };

class TestBed {
public:
    TestBed() = default;
    virtual ~TestBed() = default;

    void AddTest(std::shared_ptr<TestCase> testcase);
    bool RunTest(std::shared_ptr<TestCase> testcase);
    bool RunTest(int index);
    bool RunAllTest(RunType type = RunType::Sync);

    std::size_t GetCountTest();

private:
    using TestCases = std::vector<std::shared_ptr<TestCase>>;
    TestCases test_cases_;
    std::vector<int> failed_cases_;
};

#endif // TESTBED_H
