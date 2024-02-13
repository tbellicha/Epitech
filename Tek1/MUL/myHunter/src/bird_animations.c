/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myhunter-tanguy.bellicha
** File description:
** bird_animations
*/

#include "my.h"

void kill_animation(sfSprite *sprite)
{
    sfClock *clock = sfClock_create();
    sfVector2f scale;

    scale.x = 4;
    scale.y = 4;
    sfSprite_setTextureRect(sprite, create_rect_died());
    sfSprite_setScale(sprite, scale);
    while (sfClock_getElapsedTime(clock).microseconds <= 500000.0);
    sfClock_restart(clock);
    sfSprite_setTextureRect(sprite, create_rect_falling());
}