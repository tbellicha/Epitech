/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myhunter-tanguy.bellicha
** File description:
** window
*/

#include "my.h"

sfRenderWindow *initialise_window(void)
{
    sfVideoMode mode = {1024, 960, 32};
    sfRenderWindow *window = sfRenderWindow_create \
    (mode, "myHunter", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

sfRenderWindow *update_window(sfRenderWindow *window, sfSprite *sprite)
{
    sfTexture *backgrd = sfTexture_createFromFile("resources/background.png", NULL);
    sfSprite *bg_sprite = sfSprite_create();
    sfVector2f scale = {4, 4};

    sfSprite_setTexture(bg_sprite, backgrd, sfTrue);
    sfSprite_setScale(bg_sprite, scale);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, bg_sprite, NULL);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);
    return (window);
}

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}
