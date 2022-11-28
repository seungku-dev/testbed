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

    bool LoadConfig(std::filesystem::path path) {
        try {
            config.Load(path);
        } catch (std::exception& e) {
            syncerr << e.what() << syncend;
            return false;
        }

        return true;
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
