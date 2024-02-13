/*
** EPITECH PROJECT, 2020
** flag_third_part.c
** File description:
** third part of flags
*/

#include <stdarg.h>
#include "my.h"

int plus_flag(va_list args, ...)
{
    int final = 0;
    int entier = va_arg(args, int);

    if (entier >= 0) {
        my_putchar('+');
        final++;
    }
    if (entier < 0)
        final++;
    if (entier == 0)
        final++;
    my_putnbr_base(entier, "0123456789");
    while (entier) {
        entier /= 10;
        final++;
    }
    return (final);
}

int minus_flag(va_list args, ...)
{
    int final = 0;
    int entier = va_arg(args, int);

    if (entier == 0)
        final++;
    if (entier < 0)
        final++;
    my_putnbr_base(entier, "0123456789");
    while (entier) {
        entier /= 10;
        final++;
    }
    return (final);
}

int u_flag(va_list args, ...)
{
    int final = 0;
    unsigned long long entier = va_arg(args, unsigned long long);

    if (entier == 0)
        final++;
    my_putnbr_base(entier, "0123456789");
    while (entier) {
        entier /= 10;
        final++;
    }
    return (final);
}

void display_unprintable_char(char c)
{
    if (c > 7 && c < 32) {
        my_putchar('0');
        my_putnbr_base(c, "01234567");
    } else if (c < 8) {
        my_putchar('0');
        my_putchar('0');
        my_putnbr_base(c, "01234567");
    }
    else
        my_putnbr_base(c, "01234567");
}

int cap_s_flag(va_list args, ...)
{
    int final = 0;
    char *str = va_arg(args, char *);

    for (int i = 0; str[i]; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            display_unprintable_char(str[i]);
            final += 3;
        } else {
            my_putchar(str[i]);
            final++;
        }
    }
    return (final);
}
