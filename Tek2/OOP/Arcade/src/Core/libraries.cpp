/*
** EPITECH PROJECT, 2022
** Project
** File description:
** libraries
*/

#include "core.hpp"

template <typename T>
T *open_lib(const char* filepath, const char* symbol) {
    void *lib = dlopen(filepath, RTLD_LAZY);

    if (!lib)
        throw arcade::exception::core::LibraryLoading(dlerror());
    dlerror();
    T *ret = (T *) dlsym(lib, symbol);
    const char* dlsym_error = dlerror();
    if (dlsym_error)
        throw arcade::exception::core::LibraryLoading(dlsym_error);
    return ret;
}

std::vector<std::string> getLibraries(int mode)
{
    DIR *dir = NULL;
    struct dirent *diread = NULL;
    std::vector<std::string> files = {};
    std::string filepath = "";

    if ((dir = opendir("./lib/"))) {
        while ((diread = readdir(dir))) {
            if (strstr(diread->d_name, ".so")) {
                try {
                    filepath = "./lib/" + std::string(diread->d_name);
                    switch (mode) {
                        case MODE_GAME:
                            open_lib<create_game_t>(filepath.c_str(), CREATE_SYMBOL_GAME);
                            open_lib<destroy_game_t>(filepath.c_str(), DESTROY_SYMBOL_GAME);
                            break;

                        case MODE_GRAPH:
                            open_lib<create_graph_t>(filepath.c_str(), CREATE_SYMBOL_GRAPH);
                            open_lib<destroy_graph_t>(filepath.c_str(), DESTROY_SYMBOL_GRAPH);
                            break;
                    }
                } catch (const arcade::exception::core::Exception& e) {
                    continue;
                }
                files.push_back(filepath);
            }
        }
        closedir(dir);
    }
    return files;
}
