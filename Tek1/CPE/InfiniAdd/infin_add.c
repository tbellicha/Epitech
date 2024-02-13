/*
** EPITECH PROJECT, 2020
** infin_add
** File description:
** infin_add
*/

#include "include/my.h"
#include <stdio.h>

int infin_add(char *first_nb, char *second_nb)
{
    int retenue = 0;
    int small_result = 0;
    int pos = 0;
    int first_length = my_strlen(first_nb);
    int second_length = my_strlen(second_nb);
    char res[] = "";
    char num = '0';

    my_revstr(first_nb);
    my_revstr(second_nb);
    my_putchar('\n');
    my_putstr("First nb : ");
    my_putstr(first_nb);
    my_putstr("  |  ");
    my_put_nbr(first_length);
    my_putchar('\n');
    my_putstr("Second nb : ");
    my_putstr(second_nb);
    my_putstr("  |  ");
    my_put_nbr(second_length);
    my_putchar('\n');
    my_putchar('\n');

    while (my_strlen(first_nb) != my_strlen(second_nb)) {
        if (my_strlen(first_nb) > my_strlen(second_nb))
            my_strcat(first_nb, "0");
        if (my_strlen(second_nb) > my_strlen(first_nb))
            my_strcat(second_nb, "0");
    }

    my_putchar('\n');
    my_putstr("First nb : ");
    my_putstr(first_nb);
    my_putstr("  |  ");
    my_put_nbr(first_length);
    my_putchar('\n');
    my_putstr("Second nb : ");
    my_putstr(second_nb);
    my_putstr("  |  ");
    my_put_nbr(second_length);
    my_putchar('\n');
    my_putchar('\n');
    while (pos < my_strlen(first_nb) || pos < my_strlen(second_nb)) {
        if (!my_isnum(first_nb[pos]) && my_isnum(second_nb[pos]))
                my_add_char_to_string(first_nb, '0');
        else if (!my_isnum(second_nb[pos]) && my_isnum(first_nb[pos]))
                my_add_char_to_string(first_nb, '0');
        small_result = my_getdigit(first_nb[pos]) + \
        my_getdigit(second_nb[pos]) + retenue;
        retenue = (small_result - (small_result % 10)) / 10;
        num = my_num_to_char(small_result % 10);
        my_strncat(res, &num, 1);
        pos++;
    }
    if (retenue > 0)
        my_put_nbr(retenue);
    my_putstr(my_revstr(res));
    my_putchar('\n');
    return (0);
}