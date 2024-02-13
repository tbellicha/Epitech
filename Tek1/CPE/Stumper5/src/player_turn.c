/*
** EPITECH PROJECT, 2025
** stump5
** File description:
** Created by hjulien,
*/

#include "hangman.h"

char get_char_from_input(void)
{
    char c;
    char *line = NULL;
    int nread;
    size_t len = 0;

    nread = getline(&line, &len, stdin);
    if (nread == -1) {
        free(line);
        exit(84);
    }
    c = line[0];
    line[nread - 1] = '\0';
    free(line);
    return (c);
}

bool is_letter_in_word(game_t *game)
{
    for (int i = 0; game->word[i]; i++)
        if (game->current_letter == game->word[i])
            return (true);
    printf("%c: is not in this word\n", game->current_letter);
    return (false);
}

void reveal_letters(game_t *game)
{
    for (int i = 0; game->word[i]; i++)
        if (game->current_letter == game->word[i])
            game->hidden_word[i] = game->current_letter;
}

void make_player_turn(game_t *game)
{
    printf("Your letter : ");
    game->current_letter = get_char_from_input();
    if (is_letter_in_word(game))
        reveal_letters(game);
    else
        game->dico->tries -= 1;
}