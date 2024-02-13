/*
** EPITECH PROJECT, 2021
** check_draw.c
** File description:
** check draw
*/

#include "tictactoe.h"

int check_line(game_t *game, int i)
{
    for (int j = 0; j < game->size; j++) {
        if (game->grid[i][j] == ' ')
                return (1);
    }
    return (0);
}

int check_draw(game_t *game)
{
    for (int i = 0; i < game->size; i++) {
        if (check_line(game, i) == 1)
            return (0);
    }
    return (1);
}