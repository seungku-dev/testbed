#ifndef TESTMANAGER_H
#define TESTMANAGER_H

#include <filesystem>
#include <fstream>

#include <config.h>

namespace fs = std::filesystem;

/*
    Meyers Singleton pattern
    TestManager manages .config, VERSION, etc
 */
class TestManager {
public:
    static TestManager& GetInstance() {
        static TestManager instance;
        return instance;
    }

    bool Init();
    bool LoadConfig(fs::path path = DEFAULT_CONFIG_PATH"/default.config");
    bool LoadVersion(fs::path path = VERSION_PATH"/VERSION");

    uint32_t GenerateTestId();

private:
    TestManager() = default;
    virtual ~TestManager() = default;
    TestManager(const TestManager&) = delete;
    TestManager& operator=(const TestManager&) = delete;

    void LoadFile(fs::path path, std::ifstream& file);

    uint32_t test_id_ = 0;

    Config config_;
    std::string version_ = "unknown";
};

#endif // TESTMANAGER_H
