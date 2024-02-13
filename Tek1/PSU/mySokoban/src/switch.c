/*
** EPITECH PROJECT, 2021
** B-PSU-200-NAN-2-1-mysokoban-tanguy.bellicha
** File description:
** switch
*/

#include "my.h"
#include "sokoban.h"

void switch_move(s_soko *soko, int keycode, s_position position)
{
    switch (keycode) {
        case KEY_UP:
            move_up(soko, position);
            break;
        case KEY_RIGHT:
            move_right(soko, position);
            break;
        case KEY_DOWN:
            move_down(soko, position);
            break;
        case KEY_LEFT:
            move_left(soko, position);
            break;
    }
}

void switch_key_code(s_soko *soko, int keycode)
{
    s_position position;

    position = get_player_position(soko);
    switch (keycode) {
        case 32:
            soko->map = reset_map(soko->base_map, soko->max_height);
            break;
        case -1:
            exit (84);
            break;
        default:
            switch_move(soko, keycode, position);
    }
}