/*
** EPITECH PROJECT, 2021
** tictactoe.c
** File description:
** tic tac toe
*/

#include "tictactoe.h"
#include "my.h"

int check_status(game_t *game, int indic)
{
    if (check_win(game) == 1) {
        if (indic == 2)
            my_printf("Player 2 won!\n");
        else
            my_printf("Player 1 won!\n");
        return (1);
    }
    if (check_draw(game) == 1) {
        my_printf("Draw\n");
        return (1);
    }
    return (0);
}

int start_game(game_t *game)
{
    while (1) {
        if (do_p1_turn(game) == -1)
            return (-1);
        draw_grid(game);
        if (check_status(game, 1) == 1)
            return (0);
        if (do_p2_turn(game) == -1)
            return (-1);
        draw_grid(game);
        if (check_status(game, 2) == 1)
            return (0);
    }
    return (0);
}