/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myrunner-tanguy.bellicha
** File description:
** files
*/

#include "sokoban.h"
#include "my.h"

char *populate_str(int fd, char *buffer, char *str, int length)
{
    int size = 1;
    int i_buf = 0;
    int tempo = 0;
    int i = 0;

    while (size > 0) {
        i_buf = 0;
        if ((size = read(fd, buffer, length)) == -1)
            return ("Error");
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
    if ((str = malloc(sizeof(char) * (length + 1))) == NULL || \
    (buffer = malloc(sizeof(char) * length)) == NULL || length == 0)
        return ("Error");
    str = populate_str(fd, buffer, str, length);
    if (!my_strcmp(str, "Error"))
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
    if (!my_strcmp(map, "Error") || !check_map(map))
        return ("Error");
    return (map);
}