#ifndef CONFIG_H
#define CONFIG_H

#include <filesystem>

class Config {
public:
    Config() = default;
    virtual ~Config() = default;

    void Load(std::filesystem::path path);

private:
    const std::filesystem::path default_path_ = DEFAULT_CONFIG_PATH;
};

#endif // CONFIG_H
