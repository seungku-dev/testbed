#include <fstream>
#include <iostream>

#include <config.h>

void Config::Load(fs::path path) {
    std::cout << "Load config file: " << path << std::endl;
    if (fs::exists(path)) {
        std::ifstream in(path);

        std::string buffer;
        while (in) {
            getline(in, buffer);
            std::cout << buffer << std::endl;
        }
    }
}
