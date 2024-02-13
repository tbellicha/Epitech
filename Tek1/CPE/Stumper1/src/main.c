/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** all function for main
*/

#include "proto.h"

int main(int ac, char *argv[])
{
    if (check_error(ac, argv) == 84)
        return (84);
    return (fractals_start(my_getnbr(argv[1]), argv[2], argv[3]));
}
