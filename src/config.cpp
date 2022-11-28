#include <config.h>
#include <log.h>

void Config::Load(std::filesystem::path path) {
    if (std::filesystem::exists(path) == false) {
        syncerr << "Invliad file path: " << std::filesystem::absolute(path) << syncend;
        syncerr << "Current path: " << std::filesystem::current_path() << syncend;

        throw std::exception();
    }
}