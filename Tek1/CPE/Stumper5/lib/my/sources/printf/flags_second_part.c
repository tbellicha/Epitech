/*
** EPITECH PROJECT, 2020
** flag_second_part.c
** File description:
** second part of flags functions
*/

#include "my.h"
#include <stdarg.h>

int p_flag(va_list args, ...)
{
    int final = 0;
    unsigned long long entier = va_arg(args, unsigned long long);

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

int b_flag(va_list args, ...)
{
    int final = 0;
    int entier = va_arg(args, int);

    my_putnbr_base(entier, "01");
    while (entier) {
        entier /= 2;
        final++;
    }
    return (final);
}

int x_flag(va_list args, ...)
{
    int final = 0;
    unsigned long long entier = va_arg(args, unsigned long long);

    if (entier == 0)
        final++;
    my_putnbr_base(entier, "0123456789abcdef");
    while (entier) {
        entier /= 16;
        final++;
    }
    return (final);
}

int cap_x_flag(va_list args, ...)
{
    int final = 0;
    unsigned long long entier = va_arg(args, unsigned long long);

    if (entier == 0)
        final++;
    my_putnbr_base(entier, "0123456789ABCDEF");
    while (entier) {
        entier /= 16;
        final++;
    }
    return (final);
}

int o_flag(va_list args, ...)
{
    int final = 0;
    unsigned long long entier = va_arg(args, unsigned long long);

    if (entier == 0)
        final++;
    my_putnbr_base(entier, "01234567");
    while (entier) {
        entier /= 8;
        final++;
    }
    return (final);
}
