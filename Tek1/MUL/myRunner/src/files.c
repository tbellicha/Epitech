/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myrunner-tanguy.bellicha
** File description:
** files
*/

#include "my.h"
#include "runner.h"

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
            return (84);
    }
    if (i + 1 != total_length || i != (first_length * nb_line) + (nb_line - 1))
        return (84);
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
    str = malloc(sizeof(char) * length);
    buffer = malloc(sizeof(char) * length);
    if (str == NULL || buffer == NULL || length == 0)
        return ("Error");
    str = populate_str(fd, buffer, str, length);
    if (check_map(str) == 84)
        return ("Error");
    close(fd);
    return (str);
}

char *get_file(char *filepath)
{
    int fd = 0;
    struct stat file_stat;
    char *map;

    if (lstat(filepath, &file_stat))
        return ("Error");
    map = malloc(sizeof(char) * file_stat.st_size);
    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        close(fd);
        return ("Error");
    }
    map = read_file(fd, filepath);
    if (!my_strcmp(map, "Error"))
        return ("Error");
    for (int i = 0; map[i]; i++)
        if (!check_char(map[i]))
            return ("Error");
    return (map);
}