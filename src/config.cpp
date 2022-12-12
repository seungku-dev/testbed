#include <iostream>

#include <config.h>

void Config::Load(std::ifstream& file) {
    while (file) {
        std::string buffer;
        getline(file, buffer);
        std::cout << buffer << std::endl;
    }
}
