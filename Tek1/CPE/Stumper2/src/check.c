/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper2-tanguy.bellicha
** File description:
** check
*/

#include "proto.h"

int check_chars_of_map(char *map)
{
    int count_g = 0;

    for (int i = 0; map[i]; i++) {
        if (!check_char(map[i]))
            return (my_puterror("Invalid character in you map\n"));
        if (map[i] == 'G')
            count_g++;
    }
    if (count_g != 1) {
        my_puterror("Invalid number of Ginger square\n");
        return (0);
    }
    return (1);
}

int check_parameters(int argc, char **argv)
{
    char *map = NULL;

    if (argc != 5)
        return (my_puterror("Invalid number of arguments\n"));
    if ((my_strcmp(argv[1], "-f") != 0 || my_strcmp(argv[3], "-m") != 0) && \
    (my_strcmp(argv[3], "-f") != 0 || my_strcmp(argv[1], "-m") != 0)) {
        return (my_puterror("Invalid flags\n"));
    }
    if ((!my_str_isnum(argv[4]) || my_getnbr(argv[4]) < 0) && \
        (!my_str_isnum(argv[2]) || my_getnbr(argv[2]) < 0))
        return (my_puterror("The last parameter must be a positive number\n"));
    if (my_strcmp(argv[1], "-f") == 0)
        map = get_file(argv[2]);
    else
        map = get_file(argv[4]);
    free(map);
    return (1);
}