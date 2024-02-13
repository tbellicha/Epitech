/*
** EPITECH PROJECT, 2020
** stumper.c
** File description:
** antman
*/

#ifndef __STUMPER__

#include "my.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>

//Structure \\

//Game\\

typedef struct size {
    int x;
    int y;
} size_2i;

typedef struct game {
    int max_token;
    int actual_token;
    int actual_movement_point;
    int initial_movement_point;
    size_2i size;
    char **map;
    char *buffer;
    size_2i ginger_pos;
} game_t;

//Ginger Loop\\

void display_map(game_t *game);
int ginger_loop(game_t *game);
void get_the_case_content(game_t *game, size_2i pos);
void ginger_free(game_t *game);

//Ginger Setup\\

void browse_buffer(game_t *game);
game_t init_game(char **argv);
int ginger_setup(char **argv);

//Moove\\

void move_up(game_t *game);
void move_down(game_t *game);
void move_rigth(game_t *game);
void move_left(game_t *game);
void move_ginger(game_t *game, size_2i movement);

//Mathematical Functions\\

char *my_strcat(char *dest, char const *src);
int my_sqrt(int nb);
char **mem_alloc_2d_array(int size_x, int size_y);
int my_pow(int nb, int p);
char *load_file_in_mem(char const *filepath);

//Check\\

int check_parameters(int argc, char **argv);

//Error Manager\\

int my_puterror(char *error_message);

//Files\\

int check_map(char *map);
char *populate_str(int fd, char *buffer, char *str, int length);
char *read_file(int fd, char *filepath);
int check_char(char c);
char *get_file(char *filepath);

//Get\\

int get_line_size(char *str, int i);

size_2i get_closest_token(game_t *game);
void get_closet_token_x(game_t *game, size_2i *movement, int ring, int *found);

#define __STUMPER_
#endif
