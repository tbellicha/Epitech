/*
** EPITECH PROJECT, 2021
** mathematics_functions.c
** File description:
** all mathematics function
*/

#include "proto.h"

int get_size(char *buffer)
{
    int change = 0;

    for (int i = 0; i < my_strlen(buffer); i++) {
        if (buffer[i] == '\n')
            change++;
    }
    return (change);
}

void setup_buff_two(char *buffer, char **buff)
{
    int change = 0;
    int size = 0;

    for (int i = 0; i < my_strlen(buffer); i++) {
        if (buffer[i] != '\n') {
            buff[change][size] = buffer[i];
            size++;
        } else {
            buff[change][size] = '\0';
            size = 0;
            change++;
        }
    }
}

char **setup_buff(char *buffer)
{
    char **buff;
    int size = get_size(buffer);
    int change = 0;

    buff = malloc(sizeof(char *) * (size + 2));
    size = 0;
    for (int i = 0; i < my_strlen(buffer); i++) {
        if (buffer[i] != '\n')
            size++;
        else {
            buff[change] = malloc(sizeof(char) * (size + 2));
            size = 0;
            change++;
        }
    }
    setup_buff_two(buffer, buff);
    return (buff);
}

void free_buffer(char *buffer, char **buff)
{
    int size = get_size(buffer);

    free(buffer);
    for (int i = 0; i < size; i++)
        free(buff[i]);
    free(buff);
}

int minicut_setup(char act_opt, char delimiter, char **lines, int ac)
{
    char *buffer = load_file_in_mem();
    char **buff = setup_buff(buffer);
    game_t game;

    game.ac = ac;
    game.delimiter = delimiter;
    if (act_opt == 'c') {
        minicut_do_c(lines, ac, buff, buffer);
    }
    if (act_opt == 'f') {
        minicut_do_f(lines, game, buff, buffer);
    }
    free_buffer(buffer, buff);
    return (0);
}