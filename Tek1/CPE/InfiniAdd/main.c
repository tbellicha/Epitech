/*
** EPITECH PROJECT, 2020
** main
** File description:
** idk
*/

#include <stdio.h>
#include "include/my.h"

void infin_add(char *first_nb, char *second_nb);

int main(int argc, char **argv)
{
    if (argc != 3 || !my_str_isnum(argv[1]) || !my_str_isnum(argv[2]))
        return (84);
    else {
        my_putstr("Lancement ... \n");
        infin_add(argv[1], argv[2]);
    }
    return (0);
}