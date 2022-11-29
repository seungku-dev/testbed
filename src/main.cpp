#include <iostream>

#include <log.h>
#include <testbed.h>
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
    if (TestManager::GetInstance().LoadConfig() == false) {
        std::cout << "Failed to load configuration" << std::endl;
    }

    std::shared_ptr<TestBed> testbed(new TestBed());

    // Single Test
    testbed->RunTest(std::make_shared<MyTestCase>());

    // Multiple Test
    // for (int i=0; i<50; i++) {
    //     testbed->AddTest(std::make_shared<MyTestCase>());
    // }

    // testbed->RunAllTest(RunType::Async);

    return 0;
}
