#ifndef CONFIG_H
#define CONFIG_H

#include <filesystem>

class Config {
public:
    Config() = default;
    virtual ~Config() = default;

    void Load(std::filesystem::path path);
};

#endif // CONFIG_H
