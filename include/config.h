#ifndef CONFIG_H
#define CONFIG_H

class Config {
public:
    Config() = default;
    virtual ~Config() = default;

    bool Load() {}
};

#endif // CONFIG_H
