/*
** EPITECH PROJECT, 2021
** B-MUL-100-NAN-1-1-myrunner-tanguy.bellicha
** File description:
** end
*/

#include "my.h"
#include "runner.h"

void end_game(s_game *game)
{
    sfClock *clock = sfClock_create();

    sfText_setString(game->score->score_text, "Map finished, your score is");
    sfText_setPosition(game->score->score_text, \
    update_pos(game->window->width/4, game->window->height/5));
    sfText_setPosition(game->score->score_value, \
    update_pos(game->window->width/2, game->window->height/4));
    sfRenderWindow_clear(game->window->rendwindow, sfTransparent);
    sfRenderWindow_drawSprite(game->window->rendwindow, \
    game->background->sprite, NULL);
    draw_score_value(game);
    sfRenderWindow_drawText(game->window->rendwindow, \
    game->score->score_text, NULL);
    sfRenderWindow_display(game->window->rendwindow);
    game->play = 0;
    sfMusic_stop(game->music);
    while (sfRenderWindow_isOpen(game->window->rendwindow))
        while (sfRenderWindow_pollEvent(game->window->rendwindow, \
        &game->event))
            analyse_events(game, clock);
}

void game_over(s_game *game)
{
    sfClock *clock = sfClock_create();

    sfText_setString(game->score->score_text, "You lost, your score is");
    sfText_setPosition(game->score->score_text, \
    update_pos(game->window->width/4, game->window->height/5));
    sfText_setPosition(game->score->score_value, \
    update_pos(game->window->width/2, game->window->height/4));
    sfRenderWindow_clear(game->window->rendwindow, sfTransparent);
    sfRenderWindow_drawSprite(game->window->rendwindow, \
    game->background->sprite, NULL);
    draw_score_value(game);
    sfRenderWindow_drawText(game->window->rendwindow, \
    game->score->score_text, NULL);
    sfRenderWindow_display(game->window->rendwindow);
    game->play = 0;
    sfMusic_stop(game->music);
    while (sfRenderWindow_isOpen(game->window->rendwindow))
        while (sfRenderWindow_pollEvent(game->window->rendwindow, \
        &game->event))
            analyse_events(game, clock);
}