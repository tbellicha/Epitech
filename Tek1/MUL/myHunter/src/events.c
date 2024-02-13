/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myhunter-tanguy.bellicha
** File description:
** events
*/

#include "my.h"

void manage_mouse_click(sfMouseButtonEvent event, sfSprite *sprite)
{
    if ((event.x >= (sfSprite_getPosition(sprite).x) && event.x <= \
    (sfSprite_getPosition(sprite).x + \
    sfSprite_getTextureRect(sprite).width * 4)) && (event.y >= \
    (sfSprite_getPosition(sprite).y) && event.y <= \
    (sfSprite_getPosition(sprite).y + \
    sfSprite_getTextureRect(sprite).height * 4))) {
        my_putstr("\nClick on the sprite with following coordinates: x = ");
        kill_animation(sprite);
    } else {
        my_putstr("\nYou clicked with following coordinates: x = ");
        my_put_nbr(event.x);
        my_putstr(" and y = ");
        my_put_nbr(event.y);
        my_putstr("\nSprite coordinates: x = ");
        my_put_nbr(sfSprite_getPosition(sprite).x);
        my_putstr(" and y = ");
        my_put_nbr(sfSprite_getPosition(sprite).y);
    }
}

void analyse_events(sfRenderWindow *window, sfEvent event, sfSprite *sprite)
{
    switch (event.type) {
        case sfEvtClosed :
            close_window(window);
            break;
        case sfEvtMouseLeft :
            manage_mouse_click(event.mouseButton, sprite);
            break;
        default :
            break;
    }
}