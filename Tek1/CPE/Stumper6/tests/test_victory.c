/*
** EPITECH PROJECT, 2021
** test_victory.c
** File description:
** unit test
*/

#include "tictactoe.h"
#include <string.h>
#include <criterion/criterion.h>

Test(test_check_win, horizontally)
{
    char **av = malloc(sizeof(char *) * 1);
    int ret = 0;

    av[0] = malloc(sizeof(char) * 11);
    strcpy(av[0], "./tictactoe");
    game_t *game = check_arguments(1, av);
    game->grid[0][0] = 'X';
    game->grid[0][1] = 'X';
    game->grid[0][2] = 'X';
    ret = check_win(game);
    cr_assert_eq(ret, 1);
    free(av[0]);
    free(av);
    destroy_game(game);
}

Test(test_check_win, vertically)
{
    char **av = malloc(sizeof(char *) * 1);
    int ret = 0;

    av[0] = malloc(sizeof(char) * 11);
    strcpy(av[0], "./tictactoe");
    game_t *game = check_arguments(1, av);
    game->grid[0][0] = 'X';
    game->grid[1][0] = 'X';
    game->grid[2][0] = 'X';
    ret = check_win(game);
    cr_assert_eq(ret, 1);
    free(av[0]);
    free(av);
    destroy_game(game);
}

Test(test_check_win, down_diagonal)
{
    char **av = malloc(sizeof(char *) * 1);
    int ret = 0;

    av[0] = malloc(sizeof(char) * 11);
    strcpy(av[0], "./tictactoe");
    game_t *game = check_arguments(1, av);
    game->grid[0][0] = 'X';
    game->grid[1][1] = 'X';
    game->grid[2][2] = 'X';
    ret = check_win(game);
    cr_assert_eq(ret, 1);
    free(av[0]);
    free(av);
    destroy_game(game);
}

Test(test_check_win, up_diag)
{
    char **av = malloc(sizeof(char *) * 1);
    int ret = 0;

    av[0] = malloc(sizeof(char) * 11);
    strcpy(av[0], "./tictactoe");
    game_t *game = check_arguments(1, av);
    game->grid[2][2] = 'X';
    game->grid[1][1] = 'X';
    game->grid[0][0] = 'X';
    ret = check_win(game);
    cr_assert_eq(ret, 1);
    free(av[0]);
    free(av);
    destroy_game(game);
}