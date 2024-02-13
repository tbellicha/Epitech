/*
** EPITECH PROJECT, 2021
** check_win.c
** File description:
** check win
*/

#include "tictactoe.h"
#include "my.h"

int check_right_down(game_t *game, int i, int j)
{
    if (check_horizontally(game, i, j) == 1)
            return (1);
    if (check_vertically(game, i, j) == 1)
            return (1);
    return (0);
}

int check_diago(game_t *game, int i, int j)
{
    if (check_first_diag(game, i, j) == 1)
        return (1);
    if (check_second_diag(game, i, j) == 1)
        return (1);
    return (0);
}

int check_lines(game_t *game, int i)
{
    for (int j = 0; j < game->size; j++) {
        if (check_right_down(game, i, j) == 1)
            return (1);
        if (check_diago(game, i, j) == 1)
            return (1);
    }
    return (0);
}

int check_win(game_t *game)
{
    for (int i = 0; i < game->size; i++) {
        if (check_lines(game, i) == 1)
            return (1);
    }
    return (0);
}