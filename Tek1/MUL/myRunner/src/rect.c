/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myrunner-tanguy.bellicha
** File description:
** rect
*/

#include "my.h"
#include "runner.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left = rect->left + offset;
    if (rect->left >= max_value)
        rect->left = 0;
}

sfIntRect create_rect(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}