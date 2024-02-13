/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myrunner-tanguy.bellicha
** File description:
** get
*/

#include "my.h"
#include "runner.h"

int get_line_size(char *str, int i)
{
    while (str[i++] != '\n');
    return (i - 1);
}