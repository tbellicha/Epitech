/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myhunter-tanguy.bellicha
** File description:
** create_rect_horizontal_bird
*/

#include "my.h"

sfIntRect create_rect_top_corner_bot(void)
{
    sfIntRect rect;

    rect.top = 157;
    rect.left = 4;
    rect.width = 25;
    rect.height = 31;
    return (rect);
}

sfIntRect create_rect_top_corner_middle(void)
{
    sfIntRect rect;

    rect.top = 157;
    rect.left = 41;
    rect.width = 32;
    rect.height = 30;
    return (rect);
}

sfIntRect create_rect_top_corner_top(void)
{
    sfIntRect rect;

    rect.top = 157;
    rect.left = 83;
    rect.width = 27;
    rect.height = 32;
    return (rect);
}
