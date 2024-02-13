/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper6-tanguy.bellicha
** File description:
** grid
*/

#include "tictactoe.h"
#include "my.h"

void print_vertical(char *line)
{
    my_putchar('|');
    my_putstr(line);
    my_printf("|\n");
}

void print_horizontal(game_t *game)
{
    my_printf("+");
    for (int i = 0; i < game->size; i++)
        my_putchar('-');
    my_printf("+\n");
}

void draw_grid(game_t *game)
{
    print_horizontal(game);
    for (int i = 0; i < game->size; i++)
        print_vertical(game->grid[i]);
    print_horizontal(game);
}