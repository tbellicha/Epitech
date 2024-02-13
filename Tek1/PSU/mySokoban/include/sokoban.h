/*
** EPITECH PROJECT, 2021
** B-PSU-200-NAN-2-1-mysokoban-tanguy.bellicha
** File description:
** sokoban
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

#include <ncurses.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct position {
    int x;
    int y;
} s_position;

typedef struct soko {
    char **map;
    char **base_map;
    int max_width;
    int max_height;
    int nb_o;
} s_soko;

// CHECK.C
int add_objects(char *map, int *nb_pox, int i);
int check_wall_aside(s_soko *soko, s_position position);
int check_map(char *map);
int check_all_o(s_soko *soko);
int check_all_x(s_soko *soko);

// FILES.C
char *populate_str(int fd, char *buffer, char *str, int length);
char *get_file(char *filepath);
char *read_file(int fd, char *filepath);

// GET.C
void get_stats_of_map(s_soko *soko);
s_position get_player_position(s_soko *soko);

// MAP.C
char **reset_map(char **base_map, int max_height);
void display_map(s_soko *soko);
void initialize_game(s_soko *soko, char *str);

// MOVE.C
void move_up(s_soko *soko, s_position position);
void move_right(s_soko *soko, s_position position);
void move_down(s_soko *soko, s_position position);
void move_left(s_soko *soko, s_position position);

// SWITCH.C
void switch_move(s_soko *soko, int keycode, s_position position);
void switch_key_code(s_soko *soko, int keycode);

// WINDOW.C
void display_resize_window_message(void);
int is_window_too_small(s_soko *soko);

#endif /* !SOKOBAN_H_ */