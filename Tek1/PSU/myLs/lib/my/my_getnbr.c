/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** desc
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int nb = 0;
    int i = 0;
    int is_neg = 1;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            is_neg *= (-1);
        i++;
    }
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        nb = (nb * 10) + (str[i] - 48);
        i++;
    }
    nb *= is_neg;
    return (nb);
}

char *int_to_str(int nb)
{
    int length = 0;
    char *res;
    int tempo = nb;

    while (tempo > 0) {
        tempo /= 10;
        length++;
    }
    res = malloc(sizeof(char) * (length + 1));
    res[length] = 0;
    while (length--) {
        res[length] = nb % 10 + '0';
        nb /= 10;
    }
    return (res);
}