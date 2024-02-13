/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** desc
*/

#include "rush3.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *str;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    str = my_strcpy(str, src);
    return (str);
}
