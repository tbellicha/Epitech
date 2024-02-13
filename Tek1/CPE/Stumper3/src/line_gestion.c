/*
** EPITECH PROJECT, 2021
** mathematics_functions.c
** File description:
** all mathematics function
*/

#include "proto.h"

void change_line_two(change_line_t change_line, char **lines, \
int *line, int *size)
{
    if (lines[change_line.i][change_line.pos + 1] == '\0') {
        for (int j = my_getnbr(lines[change_line.i]); j <= \
        change_line.line_size; j++) {
            line[*size] = j;
            *size += 1;
        }
    } else {
        for (int j = my_getnbr(lines[change_line.i]); j <= \
        my_getnbr(lines[change_line.i] + change_line.pos + 1); j++) {
            line[*size] = j;
            *size += 1;
        }
    }
}

int *change_line(char **lines, int ac, int line_size, int *size)
{
    int *line = malloc(sizeof(int) * (line_size + 1));
    int pos = 0;

    for (int i = 0; i < ac; i++) {
        if (my_str_search(lines[i], '-', &pos) == false) {
            line[*size] = my_getnbr(lines[i]);
            *size += 1;
        }
        if (my_str_search(lines[i], '-', &pos) == true) {
            change_line_two((change_line_t){i, pos, line_size}, \
            lines, line, size);
        }
    }
    return (line);
}