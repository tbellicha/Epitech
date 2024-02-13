/*
** EPITECH PROJECT, 2021
** moove.c
** File description:
** moove function
*/

#include "proto.h"

void move_up(game_t *game)
{
    game->map[game->ginger_pos.y][game->ginger_pos.x] = '.';
    if (game->ginger_pos.y - 1 >= 0) {
        get_the_case_content(game, (size_2i){game->ginger_pos.y - 1, \
            game->ginger_pos.x});
        game->map[game->ginger_pos.y - 1][game->ginger_pos.x] = 'G';
        game->ginger_pos.y = game->ginger_pos.y - 1;
    } else {
        get_the_case_content(game, (size_2i){game->size.y, game->ginger_pos.x});
        game->map[game->size.y][game->ginger_pos.x] = 'G';
        game->ginger_pos.y = game->size.y;
    }
}

void move_down(game_t *game)
{
    game->map[game->ginger_pos.y][game->ginger_pos.x] = '.';
    if (game->ginger_pos.y + 1 < game->size.y) {
        get_the_case_content(game, (size_2i){game->ginger_pos.y + 1, \
            game->ginger_pos.x});
        game->map[game->ginger_pos.y + 1][game->ginger_pos.x] = 'G';
        game->ginger_pos.y = game->ginger_pos.y + 1;
    } else {
        get_the_case_content(game, (size_2i){0, game->ginger_pos.x});
        game->map[0][game->ginger_pos.x] = 'G';
        game->ginger_pos.y = 0;
    }
}

void move_left(game_t *game)
{
    game->map[game->ginger_pos.y][game->ginger_pos.x] = '.';
    if (game->ginger_pos.x - 1 >= 0) {
        get_the_case_content(game, (size_2i){game->ginger_pos.y, \
            game->ginger_pos.x - 1});
        game->map[game->ginger_pos.y][game->ginger_pos.x - 1] = 'G';
        game->ginger_pos.x = game->ginger_pos.x - 1;
    } else {
        get_the_case_content(game, (size_2i){game->ginger_pos.y, \
            game->size.x - 1});
        game->map[game->ginger_pos.y][game->size.x - 1] = 'G';
        game->ginger_pos.x = game->size.x - 1;
    }
}

void move_right(game_t *game)
{
    game->map[game->ginger_pos.y][game->ginger_pos.x] = '.';
    if (game->ginger_pos.x + 1 < game->size.x) {
        get_the_case_content(game, (size_2i){game->ginger_pos.y, \
            game->ginger_pos.x + 1});
        game->map[game->ginger_pos.y][game->ginger_pos.x + 1] = 'G';
        game->ginger_pos.x = game->ginger_pos.x + 1;
    } else {
        get_the_case_content(game, (size_2i){game->ginger_pos.y, 0});
        game->map[game->ginger_pos.y][0] = 'G';
        game->ginger_pos.x = 0;
    }
}

void move_ginger(game_t *game, size_2i movement)
{
    if (movement.x < 0) {
        move_left(game);
        return ;
    }
    else if (movement.x > 0) {
        move_right(game);
        return ;
    }
    if (movement.y < 0) {
        move_up(game);
        return ;
    }
    move_down(game);
}