/*
** EPITECH PROJECT, 2021
** B-MUL-100-NAN-1-1-myrunner-tanguy.bellicha
** File description:
** map
*/

#include "my.h"
#include "runner.h"

char *browse_map(s_game *game)
{
    if (*game->map && *game->map != ' ')
        obstacle_detected(*game->map, game);
    game->map++;
    return (game->map);
}

void obstacle_detected(char c, s_game *game)
{
    switch (c) {
        case '1':
            end_game(game);
            break;
        case '2':
            create_obstacle(game);
            break;
        case '3':
            create_cloud(game);
            break;
    }
}

void create_obstacle(s_game *game)
{
    sfVector2f scale = {0.6, 0.6};
    s_game_object *obstacle = create_object("./resources/trunk.png", update_pos\
    (game->window->width - 20, 784), create_rect(0, 0, 161, 123), scale);

    insert_in_list_obstacles(game, obstacle);
}

void create_cloud(s_game *game)
{
    sfVector2f scale = {0.24, 0.24};
    s_game_object *cloud = create_object("./resources/cloud.png", update_pos\
    (game->window->width - 20, 604), create_rect(0, 0, 733, 318), scale);

    insert_in_list_clouds(game, cloud);
}
