/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper6-tanguy.bellicha
** File description:
** my_itoa
*/

#include <stdlib.h>

char *my_strcat(char *dest, char const *srx);

int check_zero_and_negative(char *p, int nb)
{
    if (nb == 0)
        return (0);
    if (nb < 0) {
        *p++ = ' ';
        return (-nb);
    }
    return (nb);
}

void do_itoa(char *p, int nb)
{
    int tmp = 0;
    char const *digit = "0123456789";

    tmp = nb;
    while (tmp) {
        ++p;
        tmp /= 10;
    }
    *p = '\0';
    while (nb) {
        *--p = digit[nb % 10];
        nb /= 10;
    }
}

char *my_itoa(int nb)
{
    char *b = malloc(sizeof(char) * 12);
    char *p = b;

    b[0] = '\0';
    if (!(nb = check_zero_and_negative(p, nb))) {
        my_strcat(b, "0");
        return (b);
    }
    do_itoa(p, nb);
    return (b);
}
