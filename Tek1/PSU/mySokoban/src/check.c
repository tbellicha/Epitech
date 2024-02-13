/*
** EPITECH PROJECT, 2021
** B-PSU-200-NAN-2-1-mysokoban-tanguy.bellicha
** File description:
** check
*/

#include "sokoban.h"
#include "my.h"

int add_objects(char *map, int *nb_pox, int i)
{
    if (map[i] == 'P') {
        nb_pox[0]++;
        return (1);
    }
    else if (map[i] == 'O') {
        nb_pox[1]++;
        return (1);
    }
    else if (map[i] == 'X') {
        nb_pox[2]++;
        return (1);
    }
    return (0);
}

int check_wall_aside(s_soko *soko, s_position position)
{
    int blocked = 0;
    int y = position.y;
    int x = position.x;

    if ((soko->map[y][x + 1] == '#' && (soko->map[y + 1][x] == '#' \
    || soko->map[y - 1][x] == '#')) || (soko->map[y][x - 1] == '#' && \
    (soko->map[y + 1][x] == '#' || soko->map[y - 1][x] == '#')))
        blocked = 1;
    if ((soko->map[y + 1][x] == '#' && (soko->map[y][x + 1] == '#' \
    || soko->map[y][x - 1] == '#')) || (soko->map[y - 1][x] == '#' && \
    (soko->map[y][x + 1] == '#' || soko->map[y][x - 1] == '#')))
        blocked = 1;
    return (blocked);
}

int check_all_x(s_soko *soko)
{
    int i = 0;
    int k = 0;
    s_position position;
    int nb_blocked_x = 0;

    while (soko->map[i]) {
        position.x = k;
        position.y = i;
        if (soko->map[i][k] == 'X' && (check_wall_aside(soko, position) == 1 \
        && soko->base_map[position.y][position.x] != 'O'))
            nb_blocked_x++;
        if (soko->map[i][k] == '\0') {
            i++;
            k = 0;
        }
        k++;
    }
    if (nb_blocked_x == (soko->nb_o - check_all_o(soko)))
        return (0);
    return (1);
}

int check_all_o(s_soko *soko)
{
    int i = 0;
    int k = 0;
    int well_placed = 0;

    while (soko->map[i]) {
        if (soko->base_map[i][k] == 'O' && soko->map[i][k] == ' ')
            soko->map[i][k] = 'O';
        if (soko->base_map[i][k] == 'O' && soko->map[i][k] == 'X')
            well_placed++;
        if (soko->map[i][k] == '\0') {
            i++;
            k = 0;
        }
        k++;
    }
    return (well_placed);
}

int check_map(char *map)
{
    int i = 0;
    int *nb_pox = malloc(sizeof(int) * 3);

    if (nb_pox == NULL)
        exit(84);
    nb_pox[0] = 0;
    nb_pox[1] = 0;
    nb_pox[2] = 0;
    while (map[i]) {
        if (add_objects(map, nb_pox, i) == 0 && \
        (!(map[i] == ' ' || map[i] == '\n' || map[i] == '#')))
            return (0);
        i++;
    }
    if (nb_pox[0] != 1 || (nb_pox[1] != nb_pox[2]) \
    || nb_pox[1] < 1 || nb_pox[2] < 1)
        return (0);
    return (1);
}