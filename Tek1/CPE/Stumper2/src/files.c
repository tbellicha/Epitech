/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper2-tanguy.bellicha
** File description:
** files
*/

#include "proto.h"

int check_map(char *map)
{
    int i = 0;
    int first_length = 0;
    int nb_line = 0;
    int total_length = 0;

    first_length = get_line_size(map, i);
    while (map[total_length++]);
    i = 0;
    while (map[i]) {
        while (map[i] != '\n' && map[i])
            i++;
        nb_line++;
        if (map[i] && (i++ != (first_length * nb_line) + (nb_line - 1)))
            return (my_puterror("You map must be rectangular\n"));
    }
    if (i + 1 != total_length || i != (first_length * (nb_line) + nb_line))
        return (my_puterror("You map must be rectangular\n"));
    return (0);
}

char *populate_str(int fd, char *buffer, char *str, int length)
{
    int size = 1;
    int i_buf = 0;
    int tempo = 0;
    int i = 0;

    while (size > 0) {
        i_buf = 0;
        size = read(fd, buffer, length);
        tempo = size;
        while (tempo-- > 0)
            str[i++] = buffer[i_buf++];
    }
    str[i] = 0;
    return (str);
}

char *read_file(int fd, char *filepath)
{
    char *buffer;
    struct stat file_stat;
    char *str;
    int length = 0;

    if (lstat(filepath, &file_stat))
        return ("Error");
    length = file_stat.st_size;
    str = malloc(sizeof(char) * (length + 1));
    buffer = malloc(sizeof(char) * (length + 1));
    if (str == NULL || buffer == NULL || length == 0)
        return ("Error");
    str = populate_str(fd, buffer, str, length);
    if (check_map(str) == 84)
        return ("Error");
    close(fd);
    free(buffer);
    return (str);
}

int check_char(char c)
{
    switch (c) {
    case 'F':
        return (1);
    case 'T':
        return (1);
    case '.':
        return (1);
    case 'G':
        return (1);
    case '\n':
        return (1);
    default:
        return (0);
    }
}

char *get_file(char *filepath)
{
    int fd = 0;
    struct stat file_stat;
    char *map = NULL;

    if (lstat(filepath, &file_stat))
        exit(my_puterror("Error"));
    map = malloc(sizeof(char) * file_stat.st_size);
    if (map == NULL)
        exit(84);
    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        close(fd);
        exit(my_puterror("Error"));
    }
    map = read_file(fd, filepath);
    if (!my_strcmp(map, "Error") || !check_chars_of_map(map))
        exit(my_puterror("Error"));
    return (map);
}