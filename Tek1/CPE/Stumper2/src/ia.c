/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper2-tanguy.bellicha
** File description:
** ia
*/

#include "proto.h"

void get_closet_token_x(game_t *game, size_2i *movement, int ring, int *found)
{
    movement->x = (ring * 2 + 1);
    for (movement->y = -(ring * 2 + 1); movement->y <= (ring * 2 + 1); \
    movement->y++) {
        if (game->map[game->ginger_pos.y + movement->y][game->ginger_pos.x \
        + movement->x] == 'T' || game->map[game->ginger_pos.y + movement->y]\
        [game->ginger_pos.x + movement->x] == 'F') {
            *found = 1;
            break;
        }
    }
}

size_2i get_closest_token(game_t *game)
{
    int ring = 0;
    int found = 0;
    size_2i movement = {0, 0};

    while (!found) {
        movement.y = - (ring * 2 + 1);
        for (movement.x = -(ring * 2 + 1); movement.x <= (ring * 2 + 1); \
        movement.x++) {
            if (game->map[game->ginger_pos.y + movement.y][game->ginger_pos.\
            x + movement.x] == 'T' || game->map[game->ginger_pos.y + \
            movement.y][game->ginger_pos.x + movement.x] == 'F') {
                found = 1;
                break;
            }
        }
        if (found)
            break;
        get_closet_token_x(game, &movement, ring, &found);
    }
    return (movement);
}