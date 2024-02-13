/*
** EPITECH PROJECT, 2022
** Project
** File description:
** main
*/

#include "plazza.hpp"

bool isNumber(std::string s, bool acceptFloat)
{
    std::size_t char_pos = 0;
    int n_num = 0;
    int nb_point = 0;

    for (; std::isdigit(s[char_pos]) || (acceptFloat && s[char_pos] == '.'); ++char_pos)
        s[char_pos] == '.' ? ++nb_point : ++n_num;
    if (nb_point > 1 || n_num < 1)
        return false;
    return char_pos == s.size();
}

void check_args(int argc, char **argv)
{
    if (argc != 4) {
        if (argv[1] && !strcmp(argv[1], "-h")) {
            std::cout << "Usage: ./plazza mult nb t" << std::endl;
            std::cout << "\tmult\tmultiplier for the cooking time of the pizzas" << std::endl;
            std::cout << "\tnb\tnumber of cooks per kitchen" << std::endl;
            std::cout << "\tt\ttime in milliseconds to replace ingredients" << std::endl;
            exit(0);
        }
        throw exception::args::NumberOfArgs("Invalid number of arguments");
    }
    if (!isNumber((std::string)argv[1], true))
        throw exception::args::MultiplierArg("Invalid multiplier argument");
    if (!isNumber((std::string)argv[2], false) || std::atoi(argv[2]) < 1)
        throw exception::args::NumberOfCooksArg("Invalid number of cooks argument");
    if (!isNumber((std::string)argv[3], false) || std::atoi(argv[3]) < 1)
        throw exception::args::TimeArg("Invalid time argument");
}

int main(int argc, char **argv)
{
    try {
        check_args(argc, argv);
    } catch (const exception::args::Exception &e) {
        std::cout << e.what() << std::endl;
        exit(84);
    }
    plazza plazza(std::atof(argv[1]), std::atoi(argv[2]), std::atoi(argv[3]));
    clock();
    plazza.start();
}