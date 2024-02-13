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

char *load_file_in_mem(void)
{
    char *buffer;
    struct stat size;
    int security = -1;

    fstat(0, &size);
    buffer = malloc(2000);
    if (buffer == NULL)
        return (NULL);
    security = read(0, buffer, 2000);
    if (security <= 0) {
        write(2, "Read is impossible", 18);
        return (NULL);
    }
    buffer[security] = '\0';
    return (buffer);
}