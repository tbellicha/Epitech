/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-BSQ-tanguy.bellicha
** File description:
** my_show_tab
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

void my_put_tab(char **tab)
{
    int i = 0;

    while (tab[i] != 0) {
        my_putstr(tab[i]);
        i++;
    }
}

char **fill_map_with_x(char **tab, t_my_bsq buffer)
{
    int value_line = buffer.value;
    int value_col = 0;
    int k = buffer.line;
    int i = 0;

    while (value_line != 0) {
        i = buffer.col;
        value_col = buffer.value;
        while (value_col != 0) {
            tab[k][i] = 'x';
            i--;
            value_col--;
        }
        value_line--;
        k--;
    }
    return (tab);
}