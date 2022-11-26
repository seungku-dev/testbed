#include <log.h>
#include <testbed.h>

// TEST CODE --
#include <chrono>
#include <iostream>
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
    std::shared_ptr<TestBed> testbed(new TestBed());

    for (int i=0; i<50; i++) {
        testbed->AddTest(std::make_shared<MyTestCase>());
    }

    testbed->RunAllTest(RunType::Async);

    return 0;
}
