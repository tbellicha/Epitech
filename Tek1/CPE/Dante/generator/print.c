/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-johan.chrillesen
** File description:
** print
*/

#include "generator.h"

void put_start_end(t_generator *gen)
{
    int line = 0;
    int column = 0;

    while (line < gen->y) {
        column = 0;
        while (column < gen->x)
            column++;
        line++;
    }
    gen->tab[line - 1][column - 2] = 1;
    gen->tab[line - 1][column - 1] = 1;
}

void convert_int_to_chars(t_generator *gen, int line)
{
    int column = 0;

    while (column < gen->x) {
        if (gen->tab[line][column] == 0)
            gen->maze[line][column] = 'X';
        else
            gen->maze[line][column] = '*';
        column++;
    }
}

void display_maze(t_generator *gen)
{
    int line = 0;

    gen->maze = malloc(sizeof(char *) * (gen->y + 1));
    while (line < gen->y) {
        gen->maze[line] = malloc(sizeof(char) * (gen->x + 1));
        convert_int_to_chars(gen, line);
        if (gen->tab[line + 1] != NULL)
            printf("%s\n", gen->maze[line]);
        else
            printf("%s", gen->maze[line]);
        line++;
    }
}
