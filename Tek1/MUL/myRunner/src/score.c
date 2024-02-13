/*
** EPITECH PROJECT, 2021
** B-MUL-100-NAN-1-1-myrunner-tanguy.bellicha
** File description:
** score
*/

#include "my.h"
#include "runner.h"

void draw_score_value(s_game *game)
{
    sfText_setString(game->score->score_value, my_itoa(game->score->score));
    sfRenderWindow_drawText(game->window->rendwindow, \
    game->score->score_value, NULL);
}