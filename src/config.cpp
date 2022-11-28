#include <config.h>
#include <log.h>

void Config::Load(std::filesystem::path path) {

    std::cout << "current path : " << std::filesystem::current_path() << std::endl;
    std::cout << "relative path : " << path.relative_path() << std::endl;
    std::cout << "absolute path : " << std::filesystem::absolute(path) << std::endl;
    std::cout << "canonical path : " << std::filesystem::canonical(path) << std::endl;

    // syncerr << "File path: " << std::filesystem::absolute(path) << syncend;
    // syncerr << "Current path: " << std::filesystem::current_path() << syncend;

    // if (std::filesystem::exists(path) == false) {


    //     throw std::exception();
    // }
}
