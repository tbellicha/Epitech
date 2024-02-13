/*
** EPITECH PROJECT, 2021
** B-PSU-200-NAN-2-1-mysokoban-tanguy.bellicha
** File description:
** window
*/

#include "my.h"
#include "sokoban.h"

void display_resize_window_message(void)
{
    mvprintw((LINES / 2) - 1, (COLS / 2) - 8, \
    "You must enlarge");
    mvprintw((LINES / 2) + (LINES % 2), (COLS / 2) - 9, \
    "the window to play");
    refresh();
}

int is_window_too_small(s_soko *soko)
{
    if (COLS < soko->max_width || LINES < soko->max_height)
        return (1);
    return (0);
}