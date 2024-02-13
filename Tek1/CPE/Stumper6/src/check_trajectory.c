/*
** EPITECH PROJECT, 2021
** check_trajectory.c
** File description:
** check trajectory
*/

#include "tictactoe.h"

int check_horizontally(game_t *game, int i, int j)
{
    char c = game->grid[i][j];

    if ((j + (game->size - 1)) >= game->size)
        return (0);
    if (c == ' ')
        return (0);
    j++;
    for (int k = 1; k < game->size; k++, j++) {
        if (game->grid[i][j] == c)
            continue;
        else
            return (0);
    }
    return (1);
}

int check_first_diag(game_t *game, int i, int j)
{
    char c = game->grid[i][j];

    if ((i + (game->size - 1)) >= game->size || \
(j + (game->size - 1)) >= game->size)
        return (0);
    if (c == ' ')
        return (0);
    i++;
    j++;
    for (int k = 1; k < game->size; k++, i++, j++)
        if (game->grid[i][j] == c)
            continue;
        else
            return (0);
    return (1);
}

int check_second_diag(game_t *game, int i, int j)
{
    char c = game->grid[i][j];

    if ((i - (game->size - 1)) < 0 || (j + game->size - 1) >= game->size)
        return (0);
    if (c == ' ')
        return (0);
    i--;
    j++;
    for (int k = 1; k < game->size; k++, i--, j++)
        if (game->grid[i][j] == c)
            continue;
        else
            return (0);
    return (1);
}

int check_vertically(game_t *game, int i, int j)
{
    char c = game->grid[i][j];

    if ((i + (game->size - 1)) >= game->size)
        return (0);
    if (c == ' ')
        return (0);
    i++;
    for (int k = 1; k < game->size; k++, i++) {
        if (game->grid[i][j] == c)
            continue;
        else
            return (0);
    }
    return (1);
}