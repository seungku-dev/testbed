#ifndef CONFIG_H
#define CONFIG_H

#include <fstream>

class Config {
public:
    Config() = default;
    virtual ~Config() = default;

    void Load(std::ifstream& file);
};

#endif // CONFIG_H
