/*
** EPITECH PROJECT, 2021
** mathematics_functions.c
** File description:
** all mathematics function
*/

#include "proto.h"

char *my_strcat(char *dest, char const *src)
{
    int length;
    int i;

    length = 0;
    i = 0;
    while (dest[length])
        length++;
    while (src[i]) {
        dest[length] = src[i];
        length++;
        i++;
    }
    dest[length] = 0;
    return (dest);
}

int my_sqrt(int nb)
{
    int result = 0;

    if (nb < 0)
        return (0);
    for (result = 0; result * result != nb; result++) {
        if (result > nb)
            return (0);
    }
    return (result);
}

char **mem_alloc_2d_array(int size)
{
    char **str = malloc(sizeof(char *) * (size + 1));

    if (str == NULL)
        return (NULL);
    for (int i = 0; i < size; i++) {
        str[i] = malloc(sizeof(char) * (size + 1));
        for (int j = 0; j < size; j ++)
            str[i][j] = '\0';
        if (str[i] == NULL)
            return (NULL);
    }
    return (str);
}

int my_pow(int nb, int p)
{
    if (p > 0)
        nb *= my_pow(nb, p - 1);
    else if (p == 0)
        return (1);
    else
        return (0);
    return (nb);
}
