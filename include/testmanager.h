#ifndef TESTMANAGER_H
#define TESTMANAGER_H

/*
    Singleton pattern
    TestManager manages setting.config, test environment
 */
class TestManager {
public:
    static TestManager& GetInstance() {
        static TestManager instance;
        return instance;
    }

private:
    TestManager() = default;
    virtual ~TestManager() = default;
    TestManager(const TestManager&) = delete;
    TestManager& operator=(const TestManager&) = delete;
};

#endif // TESTMANAGER_H
