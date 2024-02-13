/*
** EPITECH PROJECT, 2020
** my_printf.c
** File description:
** my_printf lib
*/

#include "my.h"
#include "flags.h"
#include "my_printf.h"
#include <stdarg.h>

int use_flag(which_flag_t *which_flags, char flag, va_list args, ...)
{
    int final = 0;

    for (int i = 0; i < 14; i++)
        if (flag == which_flags[i].flag)
            final = which_flags[i].fonc_ptr(args);
    return (final);
}

int skip_minus_or_plus(char const *str)
{
    int i = 0;

    while (str[i] == '+' || str[i] == '-')
        i++;
    return (i);
}

void set_struct_ptr(which_flag_t *which_flag, which_flag_t *which_hashtag_flag)
{
    set_up_ptr_fonc_first_part(which_flag);
    set_up_ptr_fonc_second_part(which_flag);
    set_up_hashtag_ptr_fonc_first_part(which_hashtag_flag);
    set_up_hashtag_ptr_fonc_second_part(which_hashtag_flag);
}

int print_flags(const char *format, va_list args, ...)
{
    int i = -1;
    which_flag_t flags[14];
    which_flag_t hashtag_flags[14];
    int final = 0;

    set_struct_ptr(flags, hashtag_flags);
    while (format[++i]) {
        if (format[i] == '%' && format[i + 1] != '#') {
            i++;
            final += use_flag(flags, format[i], args);
            i += skip_minus_or_plus(format + i);
        } else if (format[i] == '%' && format[i + 1] == '#') {
            i += 2;
            final += use_flag(hashtag_flags, format[i], args);
        } else {
            my_putchar(format[i]);
            final++;
        }
    }
    return (final);
}

int my_printf(const char *format, ...)
{
    int res = 0;
    va_list ap;

    va_start(ap, format);
    res = print_flags(format, ap);
    va_end(ap);
    return (res);
}
