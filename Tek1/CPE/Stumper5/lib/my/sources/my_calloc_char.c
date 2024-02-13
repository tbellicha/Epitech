/*
** EPITECH PROJECT, 2020
** my_calloc.c
** File description:
** My calloc
*/

#include <stdlib.h>
#include "my.h"

char *my_memset_char(char *s, char c, size_t n)
{
    for (unsigned int i = 0; i < n; i++) {
        s[i] = c;
    }
    return (s);
}

char *my_calloc_char(size_t size, char default_char)
{
    char *s = malloc(sizeof(char) * size);

    if (s == NULL)
        return (NULL);
    my_memset_char(s, default_char, size);
    return (s);
}
