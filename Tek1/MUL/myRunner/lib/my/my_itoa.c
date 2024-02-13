/*
** EPITECH PROJECT, 2021
** B-MUL-100-NAN-1-1-myrunner-tanguy.bellicha
** File description:
** my_itoa
*/

#include <stdlib.h>

char *my_itoa(int nb)
{
    int length = 0;
    char *str = malloc(sizeof(char) * 12);
    int tempo = 0;

    tempo = nb;
    while (tempo > 0) {
        tempo /= 10;
        length++;
    }
    str[length] = 0;
    while (length--) {
        str[length] = nb % 10 + '0';
        nb /= 10;
    }
    return (str);
}