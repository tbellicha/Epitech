/*
** EPITECH PROJECT, 2025
** stump5
** File description:
** Created by hjulien,
*/

#include "hangman.h"

void free_dico(dico_t *dico)
{
    for (int i = 0; i < dico->nb_words - 1; i++)
        free(dico->array_words[i]);
    free(dico->array_words);
}

void free_game(game_t *game)
{
    free(game->hidden_word);
    free_dico(game->dico);
    free(game);
}