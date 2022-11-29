#ifndef CONFIG_H
#define CONFIG_H

#include <filesystem>

namespace fs = std::filesystem;

class Config {
public:
    Config() = default;
    virtual ~Config() = default;

    void Load(fs::path file);
};

#endif // CONFIG_H
