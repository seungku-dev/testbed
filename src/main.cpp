#include <iostream>

#include <log.h>
#include <testsuite.h>
#include <testmanager.h>

// TEST CODE --
#include <chrono>
#include <stdexcept>
#include <thread>

class MyTestCase : public TestCase {
public:
    MyTestCase() = default;
    virtual ~MyTestCase() = default;

    bool Test() override {
        syncout << "Running Test!!" << syncend;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        syncout << "Running Test Done!!" << syncend;
        
        //throw std::runtime_error("testException\n");
        return true;
    }
};
// -- TEST CODE

int main(int argc, char** argv) {
    if (TM.LoadConfig() == false) {
        std::cout << "Failed to load configuration" << std::endl;
    }

    // Single Test
    std::shared_ptr<TestCase> testcase(new MyTestCase());
    testcase->Run();

    // Multiple Test by using TestSuite
    // Running Type: Async, Sync
    std::shared_ptr<TestSuite> testsuite(new TestSuite());
    for (int i=0; i<10; i++) {
        testsuite->AddTestCase(std::make_shared<MyTestCase>());
    }
    testsuite->RunAllTestCase(RunType::Sync);

    // Single Test by using TestSuite
    testsuite->RunTestCase(5);

    return 0;
}
