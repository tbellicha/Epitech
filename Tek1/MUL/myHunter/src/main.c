/*
** EPITECH PROJECT, 2020
** CSFML
** File description:
** clear && make re && make clean && ./my_hunter
*/

#include "my.h"
#include <stdio.h>

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left = rect->left + offset;
    if (rect->left >= max_value)
        rect->left = 0;
}

sfIntRect create_rect(void)
{
    sfIntRect rect;

    rect.top = 119;
    rect.left = 0;
    rect.width = 34;
    rect.height = 26;
    return (rect);
}

sfVector2f update_position(float positionX, float positionY)
{
    sfVector2f position;

    position.x = positionX;
    position.y = positionY;
    return (position);
}

sfSprite *create_duck(sfSprite *sprite)
{
    sfTexture *texture = sfTexture_createFromFile("resources/sprites.png",  NULL);
    sfVector2f scale = {4, 4};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, create_rect_top_corner_top());
    sfSprite_setPosition(sprite, update_position(512 - (sfSprite_getTextureRect(sprite).width * 1.5), 612 - (sfSprite_getTextureRect(sprite).height * 1.5)));
    sfSprite_setScale(sprite, scale);
    return (sprite);
}

int main(void)
{
    sfRenderWindow *window = initialise_window();
    sfEvent event;
    sfSprite *sprite = create_duck(sfSprite_create());
    sfClock *clock = sfClock_create();
    //sfRenderWindow_setMouseCursorVisible(window, sfFalse);

    window = update_window(window, sprite);
    while (sfRenderWindow_isOpen(window)) {
        // if (sfClock_getElapsedTime(clock).microseconds >= 100000.0)
        //     sfClock_restart(clock);
        while (sfRenderWindow_pollEvent(window, &event))
            analyse_events(window, event, sprite);
    }
    my_putchar('\n');
    close_window(window);
}