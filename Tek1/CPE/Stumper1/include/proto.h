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

//Fractal Algorythms\\

int str_cat_fractale(char **new, char *replace, int lines);
int count_lines(char *str_one);
char *convert_new_to_old(char *old, char **new, int iterations, char *str_one);
char *modification(char *old, char *str_one, char *str_two, int iterations);
int fractals_start(int iterations, char *str_one, char *str_two);

//Error Handling\\

int my_puterror(char *error_message);
int get_number_of_chars_before_new_line(char *str);
int check_length_and_second_arg(char *iteration, char *diese_pattern, \
char *point_pattern);
int check_characters(char *arg2, char *arg3);
int check_error(int argc, char **argv);

//Mathematical Functions\\

char *my_strcat(char *dest, char const *src);
int my_sqrt(int nb);
char **mem_alloc_2d_array(int size);
int my_pow(int nb, int p);

#define __STUMPER_
#endif
