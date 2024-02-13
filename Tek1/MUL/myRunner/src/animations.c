/*
** EPITECH PROJECT, 2021
** B-MUL-100-NAN-1-1-myrunner-tanguy.bellicha
** File description:
** animations
*/

#include "my.h"
#include "runner.h"

void execute_parallax(s_game *game)
{
    if (game->play == 1) {
        move_rect(&game->ground->rect, game->window->width/120, 1440);
        sfSprite_setTextureRect(game->ground->sprite, game->ground->rect);
        move_rect(&game->bottom->rect, game->window->width/220, 720);
        sfSprite_setTextureRect(game->bottom->sprite, game->bottom->rect);
        move_rect(&game->middle->rect, game->window->width/260, 1440);
        sfSprite_setTextureRect(game->middle->sprite, game->middle->rect);
        move_rect(&game->top->rect, game->window->width/300, 1440);
        sfSprite_setTextureRect(game->top->sprite, game->top->rect);
        display_obstacles(game);
        display_clouds(game);
    }
}

void display_obstacles(s_game *game)
{
    s_obstacles *current = game->obstacle_list;
    sfFloatRect obstacle_rect;
    sfFloatRect player_rect = sfSprite_getGlobalBounds(game->player->sprite);

    while (current != NULL && current->obstacle->position.x > 0) {
        sfSprite_move(current->obstacle->sprite, \
        update_pos((-game->window->width/188) * 1.6, 0));
        obstacle_rect = sfSprite_getGlobalBounds(current->obstacle->sprite);
        obstacle_rect.left += obstacle_rect.width * 0.4;
        obstacle_rect.width *= 0.4;
        obstacle_rect.top += obstacle_rect.height * 0.8;
        if (sfFloatRect_intersects(&obstacle_rect, &player_rect, NULL))
            game_over(game);
        current = current->next;
    }
}

void display_clouds(s_game *game)
{
    s_clouds *current = game->cloud_list;
    sfFloatRect cloud_rect;
    sfFloatRect player_rect = sfSprite_getGlobalBounds(game->player->sprite);

    while (current != NULL && current->cloud->position.x > 0) {
        sfSprite_move(current->cloud->sprite, \
        update_pos((-game->window->width/128) * 1.4, 0));
        cloud_rect = sfSprite_getGlobalBounds(current->cloud->sprite);
        cloud_rect.left += cloud_rect.width * 0.2;
        cloud_rect.width *= 0.6;
        if (sfFloatRect_intersects(&cloud_rect, &player_rect, NULL))
            game_over(game);
        current = current->next;
    }
}

sfVector2f update_pos(float positionX, float positionY)
{
    sfVector2f position;

    position.x = positionX;
    position.y = positionY;
    return (position);
}