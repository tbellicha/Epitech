/*
** EPITECH PROJECT, 2020
** my_calloc.c
** File description:
** My calloc
*/

#include <stdlib.h>
#include "my.h"

int *my_memset_int(int *t, int c, int n)
{
    for (int i = 0; i < n; i++)
        t[i] = c;
    return (t);
}

int *my_calloc_int(int size, int default_int)
{
    int *t = malloc(sizeof(int) * size);

    if (t == NULL)
        return (NULL);
    my_memset_int(t, default_int, size);
    return (t);
}
