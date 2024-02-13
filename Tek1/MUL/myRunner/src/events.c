/*
** EPITECH PROJECT, 2021
** B-MUL-100-NAN-1-1-myrunner-tanguy.bellicha
** File description:
** events
*/

#include "my.h"
#include "runner.h"

void analyse_events(s_game *game, sfClock *clock)
{
    switch (game->event.type) {
        case sfEvtClosed :
            close_all(game);
            break;
        case sfEvtKeyPressed :
            game->event.key.code == sfKeySpace ? \
            jump_player(game) : 0;
            game->play == 1 ? sfMusic_stop(game->jump_sound) : 0;
            game->map = browse_map(game);
            sfClock_restart(clock);
            break;
        default:
            break;
    }
}