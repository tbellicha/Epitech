/*
** EPITECH PROJECT, 2021
** B-MUL-100-NAN-1-1-myrunner-tanguy.bellicha
** File description:
** initialization
*/

#include "my.h"
#include "runner.h"

void initialize_music(s_game *game)
{
    game->music = sfMusic_createFromFile("./resources/music.flac");
    game->jump_sound = sfMusic_createFromFile("./resources/jump.flac");
    sfMusic_play(game->music);
    sfMusic_setLoop(game->music, sfTrue);
    sfMusic_setVolume(game->music, 2);
    sfMusic_setVolume(game->jump_sound, 12);
}

s_game *initialize_variables(void)
{
    s_game *game = malloc(sizeof(*game));

    game->player = malloc(sizeof(game->player));
    game->window = malloc(sizeof(game->window));
    game->ground = malloc(sizeof(game->ground));
    game->bottom = malloc(sizeof(game->bottom));
    game->middle = malloc(sizeof(game->middle));
    game->top = malloc(sizeof(game->top));
    game->score = malloc(sizeof(game->score));
    game->obstacle_list = malloc(sizeof(game->obstacle_list));
    game->cloud_list = malloc(sizeof(game->cloud_list));
    game->background = malloc(sizeof(game->background));
    game->window->rendwindow = initialize_window(game);
    initialize_music(game);
    initiliaze_score_text(game);
    initiliaze_score_value("resources/font/FFF_Tusj.ttf", game);
    game->obstacle_list = NULL;
    game->cloud_list = NULL;
    game->play = 1;
    return (game);
}

void initiliaze_score_value(char const *filepath, s_game *game)
{
    sfFont *font = sfFont_createFromFile(filepath);
    sfVector2f value_pos = {220, 0};

    game->score->score_value = sfText_create();
    sfText_setFont(game->score->score_value, font);
    sfText_setCharacterSize(game->score->score_value, 56);
    sfText_setPosition(game->score->score_value, value_pos);
}

void initiliaze_score_text(s_game *game)
{
    sfVector2f label_pos = {20, 0};
    sfText *score_text = sfText_create();

    sfText_setFont(score_text, \
    sfFont_createFromFile("./resources/font/FFF_Tusj.ttf"));
    sfText_setCharacterSize(score_text, 56);
    sfText_setString(score_text, "Score : ");
    sfText_setPosition(score_text, label_pos);
    game->score->score_text = score_text;
}

void initialize_objects(s_game *game)
{
    sfVector2f scale_bg = {1.4, 1.4};
    sfVector2f scale_ground = {1, 1};
    sfVector2f scale_player = {1.5, 1.5};

    game->ground = create_object("./resources/ground.png", update_pos\
    (0, 420), create_rect(0, 0, game->window->width, 580), scale_ground);
    game->bottom = create_object("./resources/bottom.png", update_pos\
    (0, 240), create_rect(0, 0, game->window->width, 543), scale_bg);
    game->middle = create_object("./resources/middle.png", update_pos\
    (0, 220), create_rect(0, 0, game->window->width, 543), scale_bg);
    game->top = create_object("./resources/top.png", update_pos(0, 240), \
    create_rect(0, 0, game->window->width, 543), scale_ground);
    game->background = create_object("./resources/background.png", update_pos\
    (0, 0), create_rect(0, 0, game->window->width, 1546), scale_bg);
    game->player = create_object("./resources/sprites.png", \
    update_pos(100, 700), create_rect(0, 0, 84, 100), scale_player);
    sfTexture_setRepeated(game->ground->texture, 1);
    sfTexture_setRepeated(game->bottom->texture, 1);
    sfTexture_setRepeated(game->middle->texture, 1);
    sfTexture_setRepeated(game->top->texture, 1);
}