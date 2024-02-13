/*
** EPITECH PROJECT, 2020
** rush3
** File description:
** rush3
*/

#include "rush3.h"

void print_parameters(int length, int height, int new_line)
{
    my_put_nbr(length);
    my_putchar(' ');
    my_put_nbr(height);
    if (new_line)
        my_putchar('\n');
}

void multiple_rush_possible(int length, int height)
{
    int i = 3;
    for (; i <= 4; i++) {
        my_putstr("[rush1-");
        my_put_nbr(i);
        my_putstr("] ");
        print_parameters(length, height, 0);
        my_putstr(" || ");
    }
    my_putstr("[rush1-");
    my_put_nbr(i);
    my_putstr("] ");
    print_parameters(length, height, 1);
}

void print_rush_asked(char *buff, int length, int height, int i)
{
    if (buff[0] == 'o' && buff[length - 1] == 'o')
        my_putstr("[rush1-1] ");
    if ((buff[0] == '/' && buff[length - 1] == '\\') \
    || (buff[0] == '*' && buff[length - 1] == '*'))
        my_putstr("[rush1-2] ");
    if (buff[0] == 'A' && buff[length - 1] == 'A')
        my_putstr("[rush1-3] ");
    if (buff[0] == 'A' && buff[length - 1] == 'C' && buff[i - 2] == 'C')
        my_putstr("[rush1-4] ");
    if (buff[0] == 'A' && buff[length - 1] == 'C' && buff[i - 2] == 'A')
        my_putstr("[rush1-5] ");
    if (buff[0] == 'B' && (length == 1 || height == 1))
        multiple_rush_possible(length, height);
    if (buff[0] == ('o' || '/' || '*' || 'A' || 'B'))
        my_putstr("none\n");
}

void rush3(char buff[])
{
    int length = 0;
    int height = 0;
    int i = 0;

    while (buff[length] != '\n')
        length++;
    while (buff[i]) {
        if (buff[i] == '\n')
            height++;
        i++;
    }
    if (buff[0] != 'I' && buff[8] != 'S') {
        print_rush_asked(buff, length, height, i);
        if (buff[0] != 'B')
            print_parameters(length, height, 1);
    }
}