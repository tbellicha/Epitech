/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myrunner-tanguy.bellicha
** File description:
** main
*/

#include "my.h"
#include "runner.h"

s_game_object *create_object(const char *filepath, sfVector2f pos, \
sfIntRect rect, sfVector2f scale)
{
    s_game_object *object = malloc(sizeof(*object));

    object->texture = sfTexture_createFromFile(filepath, NULL);
    if (object->texture == NULL)
        return (NULL);
    object->rect = rect;
    object->position = pos;
    object->sprite = sfSprite_create();
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setScale(object->sprite, scale);
    sfSprite_setTextureRect(object->sprite, object->rect);
    sfSprite_setPosition(object->sprite, object->position);
    return (object);
}

void game_loop(s_game *game, sfClock *clock, sfClock *map_clock)
{
    if (sfClock_getElapsedTime(clock).microseconds >= 20000.0)
        execute_parallax(game);
    if (sfClock_getElapsedTime(clock).microseconds >= 80000.0) {
        move_rect(&game->player->rect, 85, 500);
        sfSprite_setTextureRect(game->player->sprite, game->player->rect);
        sfClock_restart(clock);
    }
    if (sfClock_getElapsedTime(map_clock).microseconds >= 500000.0) {
        game->map = browse_map(game);
        game->score->score++;
        sfClock_restart(map_clock);
    }
}

int main(int argc, char **argv)
{
    s_game *game = initialize_variables();
    sfClock *clock = sfClock_create();
    sfClock *map_clock = sfClock_create();

    if (check_params_and_map(argc, argv, game, 1) != 0)
        return (check_params_and_map(argc, argv, game, 0));
    initialize_objects(game);
    while (sfRenderWindow_isOpen(game->window->rendwindow) && game->play) {
        game_loop(game, clock, map_clock);
        while (sfRenderWindow_pollEvent(game->window->rendwindow, \
        &game->event))
            analyse_events(game, map_clock);
        update_window(game);
    }
    return (0);
}