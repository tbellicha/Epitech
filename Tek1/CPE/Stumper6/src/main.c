/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper6-tanguy.bellicha
** File description:
** main
*/

#include "tictactoe.h"
#include "my.h"

int main(int argc, char **argv)
{
    game_t *game = NULL;

    if ((game = check_arguments(argc, argv)) == NULL)
        return (84);
    draw_grid(game);
    if (start_game(game) == -1)
        return (84);
    destroy_game(game);
    return (0);
}