/*
** EPITECH PROJECT, 2021
** ginger_loop.c
** File description:
** loop for the game
*/

#include "proto.h"

void display_map(game_t *game)
{
    printf("Tokens: %i/%i\n", game->actual_token, game->max_token);
    printf("Movement points: %i\n", game->actual_movement_point);
    for (int i = 0; i < game->size.y; i++) {
        my_putstr(game->map[i]);
        my_putchar('\n');
    }
    my_putchar('\n');
}

void ginger_free(game_t *game)
{
    for (int i = 0; i < game->size.y; i++)
        free(game->map[i]);
    free(game->map);
    free(game->buffer);
}

void get_the_case_content(game_t *game, size_2i pos2)
{
    size_2i pos = {0, 0};

    pos.x = pos2.y;
    pos.y = pos2.x;
    if (game->map[pos.y][pos.x] == 'T')
        game->actual_token += 1;
    if (game->map[pos.y][pos.x] == 'F')
        game->actual_movement_point += game->initial_movement_point;
}

int ginger_loop(game_t *game)
{
    srand(time(NULL));
    display_map(game);

    while (1) {
        move_ginger(game, get_closest_token(game));
        game->actual_movement_point -= 1;
        display_map(game);
        if (game->actual_token == game->max_token) {
            printf("Ginger never loses!\n");
            break;
        } else if (game->actual_movement_point == 0) {
            printf("Ginger is too old for that!\n");
            break;
        }
    }
    ginger_free(game);
    return (0);
}