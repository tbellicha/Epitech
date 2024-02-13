/*
** EPITECH PROJECT, 2020
** my_put_nbr_base.c
** File description:
** converts and displays a decimal in a given base
*/

#include <unistd.h>
#include "my.h"

int my_isprintable(char c)
{
    if (c >= 32 && c < 127)
        return (1);
    return (0);
}

int is_same_char(char c, char *str)
{
    for (; *str; str++) {
        if (c == *str)
            return (1);
    }
    return (0);
}

int check_base(char *str)
{
    int i = 0;

    if (my_strlen(str) < 2)
        return (0);
    while (str[i]) {
        if (!(my_isprintable(str[i])))
            return (0);
        i++;
    }
    i = 0;
    while (*str) {
        if (is_same_char(*str, str + 1))
            return (0);
        str++;
    }
    return (1);
}

int my_putnbr_base(long long nbr, char *base)
{
    unsigned long long nb;
    unsigned int length = my_strlen(base);

    if (!(check_base(base)))
        return (-1);
    if (nbr < 0) {
        my_putchar('-');
        nb = nbr * (-1);
    }
    else
        nb = nbr;
    if (nb >= length)
        my_putnbr_base(nb / length, base);
    my_putchar(base[nb % length]);
    return (0);
}
