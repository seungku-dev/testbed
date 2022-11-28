#include <chrono>
#include <exception>
#include <string>

#include <log.h>
#include <testcase.h>
#include <testmanager.h>

#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"

using namespace std::chrono;

TestCase::TestCase() {
    id_ = TestManager::GetInstance().GenerateUid();
}

bool TestCase::Run() {
    bool result = false;
    auto start = steady_clock::now();

    syncout << "[  RUN!  ][ " << std::setw(3) << id_ << " ] " << typeid(*this).name() << syncend;

    try {
        result = Test();
    } catch (std::exception& e) {
        syncerr << e.what() << syncend;
        result = false;
    }

    auto end = steady_clock::now();
    auto run_time = duration_cast<milliseconds>(end-start);
    std::string test_result = result? COLOR_GREEN"PASSED": COLOR_RED"FAILED";

    syncout << "[ " << test_result << COLOR_RESET << " ]"
            << "[ " << std::setw(3) << id_ << " ] " << typeid(*this).name()
            << " (" << run_time.count() << " ms)" << syncend;

    return result;
}

void TestCase::RunAsync() {
    data_ = std::async(&TestCase::Run, this);
}

bool TestCase::Report() {
    return data_.get();
}
