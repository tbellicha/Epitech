/*
** EPITECH PROJECT, 2021
** B-MUL-100-NAN-1-1-myrunner-tanguy.bellicha
** File description:
** linked_list
*/

#include "my.h"
#include "runner.h"

void insert_in_list_obstacles(s_game *game, s_game_object *obstacle)
{
    s_obstacles *new = malloc(sizeof(s_obstacles));

    if (new == NULL)
        return ;
    new->obstacle = obstacle;
    new->next = game->obstacle_list;
    game->obstacle_list = new;
}

void add_obstacles_in_window(s_game *game)
{
    s_obstacles *current = game->obstacle_list;

    while (current != NULL) {
        sfRenderWindow_drawSprite(game->window->rendwindow, \
        current->obstacle->sprite, NULL);
        current = current->next;
    }
}

void insert_in_list_clouds(s_game *game, s_game_object *cloud)
{
    s_clouds *new = malloc(sizeof(s_clouds));

    if (new == NULL)
        return ;
    new->cloud = cloud;
    new->next = game->cloud_list;
    game->cloud_list = new;
}

void add_clouds_in_window(s_game *game)
{
    s_clouds *current = game->cloud_list;

    while (current != NULL) {
        sfRenderWindow_drawSprite(game->window->rendwindow, \
        current->cloud->sprite, NULL);
        current = current->next;
    }
}