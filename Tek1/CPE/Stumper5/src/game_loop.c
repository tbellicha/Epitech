/*
** EPITECH PROJECT, 2025
** stump5
** File description:
** Created by hjulien,
*/
// PENSER A FREE GAME WORD
#include "hangman.h"

void check_win(game_t *game)
{
    for (int i = 0; game->hidden_word[i]; i++) {
        if (game->hidden_word[i] == '*') {
            game->win = false;
            return;
        }
        else
            game->win = true;
    }
}

int game_loop(game_t *game)
{
    display_pre_game(game);
    while (game->dico->tries > 0 && !game->win) {
        check_win(game);
        if (game->win) {
            display_running_game(game);
            printf("Congratulations!\n");
            return (win);
        }
        make_player_turn(game);
        display_running_game(game);
    }
    printf("You lost!\n");
    return (lose);
}