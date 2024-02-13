/*
** EPITECH PROJECT, 2021
** B-PSU-200-NAN-2-1-mysokoban-tanguy.bellicha
** File description:
** get
*/

#include "sokoban.h"
#include "my.h"

void get_stats_of_map(s_soko *soko)
{
    int i = -1;
    int k = 0;
    int max_length = 0;
    while (soko->map[++i])
        if (my_strlen(soko->map[i]) > max_length)
            max_length = my_strlen(soko->map[i]);
    soko->max_width = max_length;
    i = 0;
    while (soko->map[i]) {
        if (soko->map[i][k] == 'O')
            soko->nb_o++;
        if (soko->map[i][k] == '\0') {
            i++;
            k = 0;
        }
        k++;
    }
    soko->max_height = i;
}

s_position get_player_position(s_soko *soko)
{
    int i = 0;
    int k = 0;
    s_position position;

    while (soko->map[i]) {
        if (soko->map[i][k] == 'P')
            break;
        if (soko->map[i][k] == '\0') {
            i++;
            k = 0;
        }
        k++;
    }
    position.x = k;
    position.y = i;
    return (position);
}