/*
** EPITECH PROJECT, 2020
** stumper.c
** File description:
** stumper
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
#include <stdbool.h>

//Structure\\

//Game\\

typedef struct size {
    int i;
    int pos;
    int line_size;
} change_line_t;

typedef struct game {
    int ac;
    char delimiter;
} game_t;

struct minicut {
    char act_op;
    char delimiter;
    char **lines;
    int nb_line;
    int ret;
};

//Proto\\

struct minicut parse_options(char **argv, struct minicut infos);

//Mathematical Functions\\

char *my_strcat(char *dest, char const *src);
int my_sqrt(int nb);
char **mem_alloc_2d_array(int size_x, int size_y);
int my_pow(int nb, int p);
char *load_file_in_mem(void);

//Line Gestion\\

void change_line_two(change_line_t change_line, char **lines, \
int *line, int *size);
int *change_line(char **lines, int ac, int line_size, int *size);

//Minicut C\\

void minicut_print_c(int *line, int line_size, char **buffer, int i);
void minicut_do_c(char **lines, int ac, char **buffer, char *buff);

//Minicut F\\

void minicut_print_f(char **stack, int *line, int j, int line_size);
void minicut_do_f(char **lines, game_t game, char **buffer, char *buff);

//Minicut Setup\\

int get_size(char *buffer);
void setup_buff_two(char *buffer, char **buff);
char **setup_buff(char *buffer);
void free_buffer(char *buffer, char **buff);
int minicut_setup(char act_opt, char delimiter, char **lines, int ac);

//My Search\\

bool my_str_search(char *str, char search, int *pos);
bool my_nbr_search(int *str, int search, int size);

//Stack Gestion\\

char **setup_stack_one(char *buffer, char delimiter, int *stack_size);
void fill_stack_two(int change, int *stack_size, char **stack, int size);
char **fill_stack(char *buffer, char delimiter, int *stack_size, char **stack);
char **setup_stack(char *buffer, char delimiter, int *stack_size);

#define __STUMPER_
#endif
