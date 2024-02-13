/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-tanguy.bellicha
** File description:
** display
*/

#include "matchstick.h"

int print_error(int index, s_matchstick *matchstick)
{
    switch (index) {
        case 0 :
            my_printf("Error: invalid input (positive number expected)\n");
            return (-1);
        case 1 :
            my_printf("Error: this line is out of range\n");
            return (-1);
        case 2 :
            my_printf("Error: you have to remove at least one match\n");
            return (-1);
        case 3 :
            my_printf("Error: not enough matches on this line\n");
            return (-1);
        case 4 :
            my_printf\
            ("Error: you cannot remove more than %d matches per turn\n", \
            matchstick->max_matches);
            return (-1);
    }
    return (0);
}

void print_n_chars(char c, int nb)
{
    for (int i = 0; i < nb; i++)
        my_printf("%c", c);
}

void draw_board(s_matchstick *matchstick)
{
    print_n_chars('*', matchstick->nb_line_base * 2 + 1);
    my_printf("\n*");
    for (int i = 0; i < matchstick->nb_line_base; i++) {
        print_n_chars(' ', ((matchstick->nb_line_base - 1) - i));
        print_n_chars('|', (matchstick->current_board[i]));
        print_n_chars(' ', ((matchstick->nb_line_base + i) - \
        matchstick->current_board[i]));
        if (i + 1 < matchstick->nb_line_base)
            my_printf("*\n*");
    }
    my_printf("*\n");
    print_n_chars('*', matchstick->nb_line_base * 2 + 1);
    my_printf("\n");
}