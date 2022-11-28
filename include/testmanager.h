#ifndef TESTMANAGER_H
#define TESTMANAGER_H

#include <config.h>

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

    uint32_t GenerateTestId() {
        return test_id_++;
    }

    bool LoadConfig() {
        return config.Load();
    }

private:
    TestManager() = default;
    virtual ~TestManager() = default;
    TestManager(const TestManager&) = delete;
    TestManager& operator=(const TestManager&) = delete;

    uint32_t test_id_ = 0;
    Config config;
};

#endif // TESTMANAGER_H
