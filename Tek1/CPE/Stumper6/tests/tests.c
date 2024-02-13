/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper6-tanguy.bellicha
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tictactoe.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(print_horizontal, regular_size, .init = redirect_all_stdout)
{
    game_t *game = malloc(sizeof(game_t));

    game->size = 3;
    print_horizontal(game);
    cr_assert_stdout_eq_str("+---+\n");
    free(game);
}

Test(print_horizontal, medium_size, .init = redirect_all_stdout)
{
    game_t *game = malloc(sizeof(game_t));

    game->size = 12;
    print_horizontal(game);
    cr_assert_stdout_eq_str("+------------+\n");
    free(game);
}

Test(print_horizontal, big_size, .init = redirect_all_stdout)
{
    game_t *game = malloc(sizeof(game_t));

    game->size = 24;
    print_horizontal(game);
    cr_assert_stdout_eq_str("+------------------------+\n");
    free(game);
}

Test(print_vertical, regular_size, .init = redirect_all_stdout)
{
    game_t *game = malloc(sizeof(game_t));

    game->grid = create_grid(4);
    print_vertical(game->grid[0]);
    cr_assert_stdout_eq_str("|    |\n");
    destroy_game(game);
}

Test(print_vertical, medium_size, .init = redirect_all_stdout)
{
    game_t *game = malloc(sizeof(game_t));

    game->grid = create_grid(12);
    print_vertical(game->grid[0]);
    cr_assert_stdout_eq_str("|            |\n");
    destroy_game(game);
}

Test(print_vertical, big_size, .init = redirect_all_stdout)
{
    game_t *game = malloc(sizeof(game_t));

    game->grid = create_grid(24);
    print_vertical(game->grid[0]);
    cr_assert_stdout_eq_str("|                        |\n");
    destroy_game(game);
}

Test(is_valid_char, valid_char)
{
    cr_assert_eq(is_valid_char('x'), 1);
}

Test(is_valid_char, invalid_char)
{
    cr_assert_eq(is_valid_char(' '), 0);
}