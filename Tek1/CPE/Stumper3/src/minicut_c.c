/*
** EPITECH PROJECT, 2021
** mathematics_functions.c
** File description:
** all mathematics function
*/

#include "proto.h"

void minicut_print_c(int *line, int line_size, char **buffer, int i)
{
    for (int j = 0; j < my_strlen(buffer[i]); j++) {
        if (my_nbr_search(line, j + 1, line_size) == true)
            my_putchar(buffer[i][j]);
    }
}

void minicut_do_c(char **lines, int ac, char **buffer, char *buff)
{
    int size = get_size(buff);
    int *line;
    int line_size = 0;

    for (int i = 0; i < size; i++) {
        line = change_line(lines, ac, my_strlen(buffer[i]), &line_size);
        minicut_print_c(line, line_size, buffer, i);
        my_putchar('\n');
        free(line);
        line_size = 0;
    }
}