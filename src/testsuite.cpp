#include <iostream>

#include <testsuite.h>

void TestSuite::AddTestCase(std::shared_ptr<TestCase> testcase) {
    testcases_.push_back(testcase);
}

bool TestSuite::RunTestCase(std::shared_ptr<TestCase> testcase) {
    return testcase->Run();
}

bool TestSuite::RunTestCase(int index) {
    if (index >= GetSize()) {
        throw;
    }

    return testcases_[index]->Run();
}

bool TestSuite::RunAllTestCase(RunType type) {
    bool result = true;
    if (type == RunType::Async) {
        for (auto const& test : testcases_) {
            test->RunAsync();
        }
        for (auto const& test : testcases_) {
            result &= test->Report();
        }
    } else {
        for (auto const& test : testcases_) {
            result &= test->Run();
        }
    }

    std::cout << "Test Result: " << result << ", Total: " << GetSize() << std::endl;
    return result;
}

std::size_t TestSuite::GetSize() {
    return testcases_.size();
}
