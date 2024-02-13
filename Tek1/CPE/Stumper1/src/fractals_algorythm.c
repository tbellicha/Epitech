/*
** EPITECH PROJECT, 2021
** fractals_alrgorythms.c
** File description:
** algorythms for the fractals
*/

#include "proto.h"

int str_cat_fractale(char **new, char *replace, int lines)
{
    char *to_cat = NULL;
    int size = 0;
    int count = 0;

    for (; replace[size] != '@'; size++);
    to_cat = malloc(sizeof(char) * (size + 1));
    if (to_cat == NULL)
        return (-1);
    for (int i = 0; replace[i]; i++) {
        if (replace[i] != '@') {
            to_cat[count] = replace[i];
            count++;
        } else {
            count = 0;
            my_strcat(new[lines], to_cat);
            lines++;
        }
    }
    my_strcat(new[lines], to_cat);
    return (0);
}

int count_lines(char *str_one)
{
    int lines = 0;

    for (int i = 0; i < my_strlen(str_one); i++) {
        if (str_one[i] == '@')
            lines++;
    }
    return (lines);
}

char *convert_new_to_old(char *old, char **new, int iterations, char *str_one)
{
    int lines = 0;
    int cols = 0;
    int size = my_pow(my_strlen(str_one), iterations);
    int i = 0;

    old = malloc(sizeof(char) * (size + 1));
    while (1) {
        if (lines == my_sqrt(my_pow(my_strlen(str_one) - count_lines(str_one)\
            , iterations)))
            break;
        if (new[lines][cols] != '\0') {
            old[i] = new[lines][cols];
            cols++;
        } else {
            lines++;
            cols = 0;
            old[i] = '\n';
        }
        i++;
    }
    return (old);
}

char *modification(char *old, char *str_one, char *str_two, int iterations)
{
    char **new = mem_alloc_2d_array(my_sqrt(my_pow(my_strlen(str_one) - \
    count_lines(str_one), iterations)));
    int lines = 0;

    if (new == NULL) {
        write(2, "Malloc Error.\n", 14);
        return (NULL);
    }
    for (int i = 0; old[i]; i++) {
        if (old[i] == '#')
            str_cat_fractale(new, str_one, lines);
        if (old[i] == '.')
            str_cat_fractale(new, str_two, lines);
        if (old[i] == '\n') {
            lines += count_lines(str_one) + 1;
        }
    }
    old = convert_new_to_old(old, new, iterations, str_one);
    return (old);
}

int fractals_start(int iterations, char *str_one, char *str_two)
{
    char *old = "#";

    for (int i = 0; i < iterations; i++) {
        old = modification(old, str_one, str_two, i + 1);
        if (old == NULL)
            return (84);
    }
    my_putstr(old);
    return (0);
}
