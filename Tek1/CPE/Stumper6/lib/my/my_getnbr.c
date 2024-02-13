/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** Write a function that returns a number, sent to the function as a string
*/

void my_putchar(char c);

#include <stddef.h>

int my_getnbr(char const *str)
{
    int result = 0;
    int neg = 1;
    int i = 0;

    if (str == NULL)
        return (0);
    while ((*str < '0' || *str > '9') && *str != '\0') {
        str++;
        i++;
    }
    if (i > 0 && *(str - 1) == '-') {
        neg = -1;
    }
    while (*str != '\0' && *str >= '0' && *str <= '9') {
        result = result * 10;
        result = result + *str - 48;
        str++;
    }
    result = result * neg;
    return (result);
}
