/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper2-tanguy.bellicha
** File description:
** get
*/

#include "proto.h"

int get_line_size(char *str, int i)
{
    while (str[i++] != '\n');
    return (i - 1);
}