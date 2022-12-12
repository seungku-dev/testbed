#include <iostream>
#include <testmanager.h>

uint32_t TestManager::GenerateTestId() {
    return test_id_++;
}

bool TestManager::LoadConfig(fs::path path) {
    try {
        config.Load(fs::canonical(path));
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return false;
    }

    return true;
}
