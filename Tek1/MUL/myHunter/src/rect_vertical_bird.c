/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myhunter-tanguy.bellicha
** File description:
** rect_vertical_bird
*/

#include "my.h"

sfIntRect create_rect_died(void)
{
    sfIntRect rect;

    rect.top = 235;
    rect.left = 0;
    rect.width = 32;
    rect.height = 32;
    return (rect);
}

sfIntRect create_rect_falling(void)
{
    sfIntRect rect;

    rect.top = 235;
    rect.left = 48;
    rect.width = 18;
    rect.height = 32;
    return (rect);
}

sfIntRect create_rect_vertical_bot(void)
{
    sfIntRect rect;

    rect.top = 197;
    rect.left = 5;
    rect.width = 24;
    rect.height = 31;
    return (rect);
}

sfIntRect create_rect_vertical_middle(void)
{
    sfIntRect rect;

    rect.top = 197;
    rect.left = 41;
    rect.width = 32;
    rect.height = 31;
    return (rect);
}

sfIntRect create_rect_vertical_top(void)
{
    sfIntRect rect;

    rect.top = 197;
    rect.left = 82;
    rect.width = 30;
    rect.height = 31;
    return (rect);
}
