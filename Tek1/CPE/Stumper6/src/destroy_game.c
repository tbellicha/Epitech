/*
** EPITECH PROJECT, 2021
** destroy_game.c
** File description:
** destroy game
*/

#include "tictactoe.h"
#include "my.h"

void destroy_game(game_t *game)
{
    for (int i = 0; i < game->size; i++)
        free(game->grid[i]);
    free(game->grid);
    free(game);
}