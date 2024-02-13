/*
** EPITECH PROJECT, 2025
** stump5
** File description:
** Created by hjulien,
*/

#include "hangman.h"

void display_pre_game(game_t *game)
{
    printf("%s\n", game->hidden_word);
    printf("Tries : %i\n", game->dico->tries);
}

void display_running_game(game_t *game)
{
    display_pre_game(game);
}