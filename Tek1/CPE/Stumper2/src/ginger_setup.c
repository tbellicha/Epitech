/*
** EPITECH PROJECT, 2021
** ginger_setup.c
** File description:
** setup_ginger
*/

#include "proto.h"

void browse_buffer(game_t *game)
{
    int count = 0;

    for (int i = 0; i < strlen(game->buffer); i++) {
        if (game->buffer[i] == 'T')
            game->max_token += 1;
        if (game->buffer[i] == '\n') {
            game->size.y += 1;
            game->size.x = count;
            count = 0;
        } else
            count++;
    }
}

game_t init_game(char **argv)
{
    game_t game;

    for (int i = 0; i < 5; i++) {
        if (my_strcmp(argv[i], "-m") == 0)
            game.actual_movement_point = my_getnbr(argv[i + 1]);
        if (my_strcmp(argv[i], "-f") == 0)
            game.buffer = load_file_in_mem(argv[i + 1]);
    }
    game.actual_token = 0;
    game.max_token = 0;
    game.size = (size_2i){0, 0};
    game.initial_movement_point = game.actual_movement_point;
    browse_buffer(&game);
    return (game);
}

int ginger_setup(char **argv)
{
    game_t game = init_game(argv);
    size_2i count = {0, 0};

    game.map = mem_alloc_2d_array(game.size.x + 1, game.size.y + 1);
    for (int i = 0; i < strlen(game.buffer); i++) {
        if (game.buffer[i] != '\n') {
            game.map[count.y][count.x] = game.buffer[i];
            if (game.map[count.y][count.x] == 'G')
                game.ginger_pos = (size_2i){count.x, count.y};
            count.x += 1;
        } else {
            game.map[count.y][count.x] = '\0';
            count.y += 1;
            count.x = 0;
        }
    }
    return (ginger_loop(&game));
}
