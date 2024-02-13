/*
** EPITECH PROJECT, 2021
** my_putstr_err.c
** File description:
** putstr error mode
*/

#include <unistd.h>

void my_putchar_err(char c)
{
    write(2, &c, 1);
}

int my_putstr_err(char const *str)
{
    int i = 0;

    while (str[i]) {
        my_putchar_err(str[i]);
        i++;
    }
    return (0);
}
