/*
** EPITECH PROJECT, 2021
** B-PSU-200-NAN-2-1-mysokoban-tanguy.bellicha
** File description:
** move
*/

#include "sokoban.h"
#include "my.h"

void move_up(s_soko *soko, s_position position)
{
    if (soko->map[position.y - 1][position.x] != '#' && \
    !(soko->map[position.y - 1][position.x] == 'X' && \
    (soko->map[position.y - 2][position.x] != ' ' && \
    soko->map[position.y - 2][position.x] != 'O'))) {
        if (soko->map[position.y - 1][position.x] == 'X')
            soko->map[position.y - 2][position.x] = 'X';
        soko->map[position.y][position.x] = ' ';
        soko->map[position.y - 1][position.x] = 'P';
    }
}

void move_right(s_soko *soko, s_position position)
{
    if (soko->map[position.y][position.x + 1] != '#' && \
    !(soko->map[position.y][position.x + 1] == 'X' && \
    (soko->map[position.y][position.x + 2] != ' ' && \
    soko->map[position.y][position.x + 2] != 'O'))) {
        if (soko->map[position.y][position.x + 1] == 'X')
            soko->map[position.y][position.x + 2] = 'X';
        soko->map[position.y][position.x] = ' ';
        soko->map[position.y][position.x + 1] = 'P';
    }
}

void move_down(s_soko *soko, s_position position)
{
    if (soko->map[position.y + 1][position.x] != '#' && \
    !(soko->map[position.y + 1][position.x] == 'X' && \
    (soko->map[position.y + 2][position.x] != ' ' && \
    soko->map[position.y + 2][position.x] != 'O'))) {
        if (soko->map[position.y + 1][position.x] == 'X')
            soko->map[position.y + 2][position.x] = 'X';
        soko->map[position.y][position.x] = ' ';
        soko->map[position.y + 1][position.x] = 'P';
    }
}

void move_left(s_soko *soko, s_position position)
{
    if (soko->map[position.y][position.x - 1] != '#' && \
    !(soko->map[position.y][position.x - 1] == 'X' && \
    (soko->map[position.y][position.x - 2] != ' ' && \
    soko->map[position.y][position.x - 2] != 'O'))) {
        if (soko->map[position.y][position.x - 1] == 'X')
            soko->map[position.y][position.x - 2] = 'X';
        soko->map[position.y][position.x] = ' ';
        soko->map[position.y][position.x - 1] = 'P';
    }
}