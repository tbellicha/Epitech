/*
** EPITECH PROJECT, 2021
** B-MUL-100-NAN-1-1-myrunner-tanguy.bellicha
** File description:
** jump
*/

#include "my.h"
#include "runner.h"

void go_high(s_game *game, sfClock *clock, int i)
{
    execute_parallax(game);
    if (game->play == 1) {
        game->player->position = update_pos(game->player->position.x, \
        game->player->position.y - (24 - i * 2));
        sfSprite_setPosition(game->player->sprite, game->player->position);
        update_window(game);
        sfClock_restart(clock);
    }
}

void go_down(s_game *game, sfClock *clock, int i)
{
    execute_parallax(game);
    if (game->play == 1) {
        game->player->position = update_pos(game->player->position.x, \
        game->player->position.y + (24 - i * 2));
        sfSprite_setPosition(game->player->sprite, game->player->position);
        update_window(game);
        sfClock_restart(clock);
    }
}

void jump_player(s_game *game)
{
    sfClock *clock = sfClock_create();
    int i = 0;

    game->player->rect.top += 160;
    game->player->rect.left = 0;
    sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    sfMusic_play(game->jump_sound);
    while (i < 12)
        if (sfClock_getElapsedTime(clock).microseconds >= 20000.0)
            go_high(game, clock, i++);
    game->score->score++;
    game->player->rect.left = 85;
    sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    while (i >= 0)
        if (sfClock_getElapsedTime(clock).microseconds >= 20000.0)
            go_down(game, clock, i--);
    game->score->score++;
    game->player->rect.left = 0;
    game->player->rect.top -= 160;
    game->player->position = update_pos(100, 700);
}