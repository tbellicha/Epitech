/*
** EPITECH PROJECT, 2025
** stump5
** File description:
** Created by hjulien,
*/

#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int get_file_size(const char *pathname)
{
    struct stat fstat;

    stat(pathname, &fstat);
    return (fstat.st_size);
}

char *file_to_string(const char *pathname)
{
    int file_size = get_file_size(pathname);
    int fd = open(pathname, O_RDONLY);
    char *str = NULL;

    if (fd == -1) {
        my_putstr_err("Error while loading file\n");
        return (NULL);
    }
    str = malloc((sizeof(char) * file_size) + 1);
    if (!str) {
        my_putstr_err("Error while loading file\n");
        return (NULL);
    }
    read(fd, str, file_size);
    str[file_size] = '\0';
    close(fd);
    return (str);
}
