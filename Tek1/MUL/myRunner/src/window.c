/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myrunner-tanguy.bellicha
** File description:
** window
*/

#include "my.h"
#include "runner.h"

sfRenderWindow *initialize_window(s_game *game)
{
    int width = 1240;
    int height = 960;

    game->window->height = height;
    game->window->width = width;
    sfVideoMode mode = {width, height, 32};
    sfRenderWindow *window = sfRenderWindow_create\
    (mode, "myRunner", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

void update_window(s_game *game)
{
    sfRenderWindow_clear(game->window->rendwindow, sfTransparent);
    sfRenderWindow_drawSprite(game->window->rendwindow, \
    game->background->sprite, NULL);
    sfRenderWindow_drawSprite(game->window->rendwindow, \
    game->top->sprite, NULL);
    sfRenderWindow_drawSprite(game->window->rendwindow, \
    game->middle->sprite, NULL);
    sfRenderWindow_drawSprite(game->window->rendwindow, \
    game->bottom->sprite, NULL);
    sfRenderWindow_drawSprite(game->window->rendwindow, \
    game->ground->sprite, NULL);
    sfRenderWindow_drawSprite(game->window->rendwindow, \
    game->player->sprite, NULL);
    add_obstacles_in_window(game);
    add_clouds_in_window(game);
    draw_score_value(game);
    sfRenderWindow_drawText(game->window->rendwindow, \
    game->score->score_text, NULL);
    sfRenderWindow_display(game->window->rendwindow);
}

void close_all(s_game *game)
{
    sfRenderWindow_close(game->window->rendwindow);
    sfMusic_destroy(game->music);
    sfMusic_destroy(game->jump_sound);
}