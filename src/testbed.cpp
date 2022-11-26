#include <log.h>
#include <testbed.h>

void TestBed::AddTest(std::shared_ptr<TestCase> testcase) {
    test_cases_.push_back(testcase);
}

bool TestBed::RunTest(std::shared_ptr<TestCase> testcase) {
    return testcase->Run();
}

bool TestBed::RunTest(int index) {
    if (index >= GetCountTest()) {
        throw;
    }

    return test_cases_[index]->Run();
}

bool TestBed::RunAllTest(RunType type) {
    bool result = true;
    if (type == RunType::Async) {
        for (auto const& test : test_cases_) {
            test->RunAsync();
        }
        for (auto const& test : test_cases_) {
            result &= test->Report();
        }
    } else {
        for (auto const& test : test_cases_) {
            result &= test->Run();
        }
    }

    syncout << "Test Result: " << result << ", Total: " << GetCountTest() << syncend;
    return result;
}

std::size_t TestBed::GetCountTest() {
    return test_cases_.size();
}
