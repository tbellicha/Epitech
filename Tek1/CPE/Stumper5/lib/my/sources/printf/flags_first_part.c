/*
** EPITECH PROJECT, 2020
** flags_first_part.c
** File description:
** first part of flags
*/

#include <stdarg.h>
#include "my.h"

int i_flag(va_list args, ...)
{
    int entier = va_arg(args, int);
    int final = 0;

    my_putnbr_base(entier, "0123456789");
    if (entier == 0)
        final++;
    if (entier < 0)
        final++;
    while (entier) {
        entier /= 10;
        final++;
    }
    return (final);
}

int d_flag(va_list args, ...)
{
    int entier = va_arg(args, int);
    int final = 0;

    my_putnbr_base(entier, "0123456789");
    if (entier == 0)
        final++;
    if (entier < 0)
        final++;
    while (entier) {
        entier /= 10;
        final++;
    }
    return (final);
}

int c_flag(va_list args, ...)
{
    char c = va_arg(args, int);
    int final = 0;

    my_putchar(c);
    final++;
    return (final);
}

int s_flag(va_list args, ...)
{
    char *str = va_arg(args, char *);
    int final = 0;

    my_putstr(str);
    final += my_strlen(str);
    return (final);
}

int mod_flag(void)
{
    int final = 0;

    my_putchar('%');
    final++;
    return (final);
}
