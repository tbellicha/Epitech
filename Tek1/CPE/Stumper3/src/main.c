/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** all function for main
*/

#include "proto.h"

int main(int ac, char **argv)
{
    int i = 1;
    struct minicut informations = {0, '\t', NULL, 0, 0};

    if (ac % 2)
        return (84);
    ac -= 1;
    while (ac > 0) {
        informations = parse_options(&argv[i], informations);
        if (informations.ret == 84)
            return (84);
        i += 2;
        ac -= 2;
    }
    return (minicut_setup(informations.act_op, informations.delimiter, \
    informations.lines, informations.nb_line));
}
