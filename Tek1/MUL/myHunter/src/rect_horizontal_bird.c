/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myhunter-tanguy.bellicha
** File description:
** create_rect_horizontal_bird
*/

#include "my.h"

sfIntRect create_rect_horizontal_bot(void)
{
    sfIntRect rect;

    rect.top = 119;
    rect.left = 0;
    rect.width = 34;
    rect.height = 26;
    return (rect);
}

sfIntRect create_rect_horizontal_middle(void)
{
    sfIntRect rect;

    rect.top = 119;
    rect.left = 40;
    rect.width = 40;
    rect.height = 26;
    return (rect);
}

sfIntRect create_rect_horizontal_top(void)
{
    sfIntRect rect;

    rect.top = 119;
    rect.left = 81;
    rect.width = 34;
    rect.height = 28;
    return (rect);
}
