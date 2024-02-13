/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-BSQ-tanguy.bellicha
** File description:
** main
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int get_all_map(int fd, char *str)
{
    int size = 1;
    char buffer[4096];
    int	i = 0;
    int	count = 0;
    int	tempo = 0;

    while (size != 0) {
        count = 0;
        size = read(fd, buffer, 4096);
        tempo = size;
        while (tempo-- > 0)
            str[i++] = buffer[count++];
    }
    return (0);
}

char *skip_first_line(char *str)
{
    while (*str != '\n')
        str++;
    str++;
    return (str);
}

int	main(int argc, char **argv)
{
    struct stat file_stat;
    char *str;
    int	count = 0;
    int fd = open(argv[1], O_RDONLY);

    if (argc != 2 || fd == -1)
        return (84);
    stat(argv[1], &file_stat);
    str = malloc(sizeof(char *) * file_stat.st_size);
    if (get_all_map(fd, str) == 84)
        return (84);
    count = my_getnbr(str);
    get_all_map(fd, str);
    str = skip_first_line(str);
    if (make_and_display_tab(str, count, 0) == 84)
        return (84);
    make_and_display_tab(str, count, 1);
    return (0);
}