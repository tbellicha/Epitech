/*
** EPITECH PROJECT, 2021
** mathematics_functions.c
** File description:
** all mathematics function
*/

#include "proto.h"

char **setup_stack_one(char *buffer, char delimiter, int *stack_size)
{
    int size = 0;

    buffer[my_strlen(buffer) + 1] = '\0';
    buffer[my_strlen(buffer)] = delimiter;
    for (int i = 0; i < my_strlen(buffer); i++) {
        if (buffer[i] == delimiter)
            size++;
    }
    *stack_size = size;
}

void fill_stack_two(int change, int *stack_size, char **stack, int size)
{
    if (change < *stack_size - 1) {
        stack[change][size + 1] = '\0';
    } else
        stack[change][size] = '\0';
}

char **fill_stack(char *buffer, char delimiter, int *stack_size, char **stack)
{
    int change = 0;
    int size = 0;

    for (int i = 0; i < my_strlen(buffer); i++) {
        if (buffer[i] != delimiter && buffer[i] != '\n') {
            stack[change][size] = buffer[i];
            size++;
        } else {
            stack[change][size] = delimiter;
            fill_stack_two(change, stack_size, stack, size);
            size = 0;
            change++;
        }
    }
}

char **setup_stack(char *buffer, char delimiter, int *stack_size)
{
    char **stack;
    int size = 0;
    int change = 0;

    setup_stack_one(buffer, delimiter, stack_size);
    stack = malloc(sizeof(char *) * (*stack_size + 2));
    for (int i = 0; i < my_strlen(buffer); i++) {
        if (buffer[i] != delimiter && buffer[i] != '\n')
            size++;
        else {
            stack[change] = malloc(sizeof(char) * (size + 2));
            size = 0;
            change++;
        }
    }
    fill_stack(buffer, delimiter, stack_size, stack);
    return (stack);
}