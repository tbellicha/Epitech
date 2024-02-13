/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper6-tanguy.bellicha
** File description:
** initialization
*/

#include "tictactoe.h"
#include "my.h"

int is_valid_char(char c)
{
    if (c == ' ' || c == '|' || c == '-' || c == '+')
        return (0);
    return (1);
}

int manage_flag(game_t *game, char *flag, char *value)
{
    if (!my_strcmp(flag, "-p1") && game->char1 == 'X' && my_strlen(value) == 1 \
    && value[0] != game->char2 && is_valid_char(value[0])) {
        game->char1 = value[0];
        return (1);
    }
    if (!my_strcmp(flag, "-p2") && game->char2 == 'O' && my_strlen(value) == 1 \
    && value[0] != game->char1 && is_valid_char(value[0])) {
        game->char2 = value[0];
        return (1);
    }
    if (!my_strcmp(flag, "-s") && game->size == 3 && my_str_isnum(value) && \
        my_getnbr(value) > 2) {
        game->size = my_getnbr(value);
        return (1);
    }
    return (0);
}

char **create_grid(int size)
{
    char **array = malloc(sizeof(char *) * (size + 1));

    for (int i = 0; i < size; i++) {
        array[i] = malloc(sizeof(char) * (size + 1));
        array[i][size] = 0;
        for (int k = 0; k < size; k++)
            array[i][k] = ' ';
    }
    array[size] = 0;
    return (array);
}

game_t *check_arguments(int argc, char **argv)
{
    game_t *game = malloc(sizeof(game_t));

    if (argc % 2 != 1 || game == NULL)
        return (NULL);
    game->char1 = 'X';
    game->char2 = 'O';
    game->size = 3;
    for (int i = 1; i < argc; i += 2)
        if (!manage_flag(game, argv[i], argv[i + 1]))
            return (NULL);
    game->grid = create_grid(game->size);
    return (game);
}