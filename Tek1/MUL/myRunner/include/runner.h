/*
** EPITECH PROJECT, 2020
** runner.h
** File description:
** runner
*/

#ifndef RUNNER_H_
#define RUNNER_H_

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct game_object
{
    char *type;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect rect;
} s_game_object;

typedef struct t_window
{
    int width;
    int height;
    sfRenderWindow *rendwindow;
} s_window;

typedef struct obstacles s_obstacles;
struct obstacles
{
    s_game_object *obstacle;
    s_obstacles *next;
};

typedef struct clouds s_clouds;
struct clouds
{
    s_game_object *cloud;
    s_clouds *next;
};

typedef struct t_score
{
    sfText *score_text;
    sfText *score_value;
    int score;
} s_score;

typedef struct t_game
{
    s_window *window;
    sfEvent event;
    s_game_object *player;
    sfMusic *music;
    sfMusic *jump_sound;

    s_game_object *ground;
    s_game_object *bottom;
    s_game_object *middle;
    s_game_object *top;
    s_game_object *background;

    s_obstacles *obstacle_list;
    s_clouds *cloud_list;
    char *map;
    s_score *score;

    int play;
} s_game;

// animation.c
void execute_parallax(s_game *game);
void display_obstacles(s_game *game);
void display_clouds(s_game *game);
sfVector2f update_pos(float positionX, float positionY);

// check.c
int check_parameters(int argc, char **argv, s_game *game, int display);
int check_char(char c);
int check_params_and_map(int argc, char **argv, s_game *game, int display);

// end.c
void game_over(s_game *game);
void end_game(s_game *game);

// events.c
void analyse_events(s_game *game, sfClock *clock);

// files.c
int check_map(char *map);
char *populate_str(int fd, char *buffer, char *str, int length);
char *read_file(int fd, char *filepath);
char *get_file(char *filepath);

// get.c
int get_line_size(char *str, int i);

// initialization.c
void initialize_music(s_game *game);
s_game *initialize_variables(void);
void initiliaze_score_value(char const *filepath, s_game *game);
void initiliaze_score_text(s_game *game);
void initialize_objects(s_game *game);

// jump.c
void go_high(s_game *game, sfClock *clock, int i);
void go_down(s_game *game, sfClock *clock, int i);
void jump_player(s_game *game);

// linked_list.c
void insert_in_list_obstacles(s_game *game, s_game_object *obstacle);
void add_obstacles_in_window(s_game *game);
void insert_in_list_clouds(s_game *game, s_game_object *cloud);
void add_clouds_in_window(s_game *game);

// main.c
int main(int argc, char **argv);
s_game_object *create_object(const char *filepath, sfVector2f pos, \
sfIntRect rect, sfVector2f scale);
void game_loop(s_game *game, sfClock *clock, sfClock *map_clock);

// map.c
char *browse_map(s_game *game);
void obstacle_detected(char c, s_game *game);
void create_obstacle(s_game *game);
void create_cloud(s_game *game);

// rect.c
void move_rect(sfIntRect *rect, int offset, int max_value);
sfIntRect create_rect(int top, int left, int width, int height);

// score.c
void draw_score_value(s_game *game);

// window.c
sfRenderWindow *initialize_window(s_game *game);
void update_window(s_game *game);
void close_all(s_game *game);

#endif /* !RUNNER_H_ */