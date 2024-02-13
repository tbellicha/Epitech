/*
** EPITECH PROJECT, 2021
** mathematics_functions.c
** File description:
** all mathematics function
*/

#include "proto.h"

void minicut_print_f(char **stack, int *line, int j, int line_size)
{
    if (my_nbr_search(line, j + 1, line_size) == true)
        my_putstr(stack[j]);
}

int get_max_line(int *line, int line_size)
{
    int max = 0;

    for (int i = 0; i < line_size; i++) {
        if (max < line[i])
            max = line[i];
    }
    return (max);
}

void minicut_do_f(char **lines, game_t game, char **buffer, char *buff)
{
    int size = get_size(buff);
    int *line;
    int line_size = 0;
    int stack_size = 0;
    char **stack;

    for (int i = 0; i < size; i++) {
        line = change_line(lines, game.ac, my_strlen(buffer[i]), &line_size);
        stack = setup_stack(buffer[i], game.delimiter, &stack_size);
        for (int j = 0; j < stack_size; j++) {
            if (j >= get_max_line(line, line_size) - 1)
                stack[j][my_strlen(stack[j]) - 1] = '\0';
            minicut_print_f(stack, line, j, line_size);
        }
        my_putchar('\n');
        free(line);
        for (int j = 0; j < stack_size; j++)
            free(stack[j]);
        free(stack);
        line_size = 0;
    }
}
