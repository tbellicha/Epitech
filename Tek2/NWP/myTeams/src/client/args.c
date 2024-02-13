/*
** EPITECH PROJECT, 2022
** Project
** File description:
** args
*/

#include "client.h"

#include <stdio.h>
#include <string.h>

enum args_handling check_args(int argc, char const **argv)
{
    if (argc == 2) {
        if (!strcmp(argv[1], "-help")) {
            print_client_help();
            return ARGS_HELPER;
        }
    }
    if (argc == 3)
        return ARGS_VALID;
    puts("Invalid number of arguments, try with ./myteams_cli -help.");
    return ARGS_INVALID;
}
