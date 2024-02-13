/*
** EPITECH PROJECT, 2025
** lib_propre
** File description:
** Created by hjulien,
*/

#include "hangman.h"

int main(int ac, char **av)
{
    game_t *game;
    int res;

    if (!check_errors(ac))
        exit(84);
    game = game_init(ac, av);
    if (!game)
        exit(84);
    res = game_loop(game);
    free_game(game);
    return (res);
}