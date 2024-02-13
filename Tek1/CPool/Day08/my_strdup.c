/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** 
*/

#include <stdlib.h>
#include "../Librairie/include/my.h"

char *my_strdup(char const *src)
{
    char *str;
    int i;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    str = my_strcpy(str, src);
    return (str);
}
