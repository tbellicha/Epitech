/*
** EPITECH PROJECT, 2022
** Project
** File description:
** args
*/

#include "pano.h"

CHECK_ARGS_RETURN check_args(int argc, char **argv)
{
    if (argc != 5)
        return CHECK_ARGS_RETURN_HELPER;
    for (int i = 1; i < argc; i++)
        if (!my_strisnum(argv[i]) || !(atoi(argv[i]) > 0))
            return CHECK_ARGS_RETURN_ERROR;
    return CHECK_ARGS_RETURN_OK;
}