/*
** EPITECH PROJECT, 2020
** hashtag_flag.c
** File description:
** functions for hashtag flag
*/

#include <stdarg.h>
#include "my.h"

int x_hashtag_flag(va_list args, ...)
{
    int final = 0;
    int entier = va_arg(args, int);

    if (entier == 0)
        final++;
    else {
        my_putchar('0');
        my_putchar('x');
        final +=2;
    }
    my_putnbr_base(entier, "0123456789abcdef");
    while (entier) {
        entier /= 16;
        final++;
    }
    return (final);
}

int cap_x_hashtag_flag(va_list args, ...)
{
    int final = 0;
    int entier = va_arg(args, int);

    if (entier == 0)
        final++;
    else {
        my_putchar('0');
        my_putchar('X');
        final +=2;
    }
    my_putnbr_base(entier, "0123456789ABCDEF");
    while (entier) {
        entier /= 16;
        final++;
    }
    return (final);
}

int o_hashtag_flag(va_list args, ...)
{
    int final = 0;
    unsigned int entier = va_arg(args, unsigned int);

    if (entier == 0)
        final++;
    else {
        my_putchar('0');
        final++;
    }
    my_putnbr_base(entier, "01234567");
    while (entier) {
        entier /= 8;
        final++;
    }
    return (final);
}
