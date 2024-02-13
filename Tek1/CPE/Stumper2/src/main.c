/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** all function for main
*/

#include "proto.h"

int main(int ac, char *argv[])
{
    if (check_parameters(ac, argv) == 84)
        return (84);
    return (ginger_setup(argv));
}
