/*
** EPITECH PROJECT, 2021
** player_turn.c
** File description:
** player turn
*/

#include "tictactoe.h"
#include "my.h"

int check_input_nb2(game_t *game, int nb2, char *first_input_value, char *input)
{
    if (nb2 >= game->size || (input[my_strlen(first_input_value) + 1] < '0' \
    || input[my_strlen(first_input_value) + 1] > '9')) {
        free(first_input_value);
        return (-1);
    }
    return (0);
}

int check_separator(char *input, char *first_input_value)
{
    if (input[my_strlen(first_input_value)] != ',') {
        free(first_input_value);
        return (-1);
    }
    return (0);
}

int check_input(game_t *game, char *input)
{
    int nb1 = 0;
    int nb2 = 0;
    char *first_input_value = NULL;

    nb1 = my_getnbr(input);
    if (nb1 >= game->size || (input[0] < '0' || input[0] > '9'))
        return (-1);
    first_input_value = my_itoa(nb1);
    if (check_separator(input, first_input_value) == -1)
        return (-1);
    nb2 = my_getnbr(&input[my_strlen(first_input_value) + 1]);
    if (check_input_nb2(game, nb2, first_input_value, input) == -1)
        return (-1);
    if (game->grid[nb2][nb1] != ' ') {
        free(first_input_value);
        return (-1);
    }
    free(first_input_value);
    return (0);
}

int do_p1_turn(game_t *game)
{
    char *input = NULL;
    size_t n = 0;
    int x = 0;
    int y = 0;
    char *first_value = NULL;

    while (1) {
        my_printf("Player 1> ");
        if (getline(&input, &n, stdin) == -1)
            return (-1);
        if (check_input(game, input) == 0)
            break;
    }
    x = my_getnbr(input);
    first_value = my_itoa(x);
    y = my_getnbr(&input[my_strlen(first_value) + 1]);
    game->grid[y][x] = game->char1;
    free(input);
    free(first_value);
    return (0);
}

int do_p2_turn(game_t *game)
{
    char *input = NULL;
    size_t n = 0;
    int x = 0;
    int y = 0;
    char *first_value = NULL;

    while (1) {
        my_printf("Player 2> ");
        if (getline(&input, &n, stdin) == -1)
            return (-1);
        if (check_input(game, input) == 0)
            break;
    }
    x = my_getnbr(input);
    first_value = my_itoa(x);
    y = my_getnbr(&input[my_strlen(first_value) + 1]);
    game->grid[y][x] = game->char2;
    free(input);
    free(first_value);
    return (0);
}