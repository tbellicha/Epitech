/*
** EPITECH PROJECT, 2022
** RUSH3
** File description:
** check_params
*/

#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include "InfoModule.hpp"
#include "CoreInfo.hpp"
#include "AllMonitors.hpp"
#include "include.hpp"

void help()
{
    std::cout << "MyGKrellm" << std::endl;
    std::cout << "-g\t\tDisplay graphical application" << std::endl;
    std::cout << "-t\t\tDisplay text application" << std::endl;
    std::cout << "-h\t\tPrint help" << std::endl;
    exit(0);
}

bool compute_params(char** argv)
{
    if (!strcmp(argv[1], "-g")) {
        computeSFML();
        return (true);
    } else if (!strcmp(argv[1], "-t")) {
        computeNCurse();
        return (true);
    }
    help();
    return (false);
}

bool check_params(int argc, char** argv)
{
    if (argc != 2)
        help();
    return (compute_params(argv));
}