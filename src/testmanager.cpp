#include <iostream>
#include <testmanager.h>

bool TestManager::Init() {
    if (LoadConfig() == false) {
        std::cout << "Failed to load configuration" << std::endl;
    }

    if (LoadVersion() == false) {
        std::cout << "Failed to load version" << std::endl;
    }

    return true;
}

uint32_t TestManager::GenerateTestId() {
    return test_id_++;
}

void TestManager::LoadFile(fs::path path, std::ifstream& file) {
    if (fs::exists(fs::canonical(path)))
        file.open(path);
}

bool TestManager::LoadConfig(fs::path path) {
    std::ifstream file;
    try {
        LoadFile(path, file);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return false;
    }

    config_.Load(file);
    return true;
}

bool TestManager::LoadVersion(fs::path path) {
    std::ifstream file;
    try {
        LoadFile(path, file);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return false;
    }

    getline(file, version_);
    std::cout << "ver." << version_ << std::endl;

    return true;
}
