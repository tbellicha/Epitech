/*
** EPITECH PROJECT, 2021
** mathematics_functions.c
** File description:
** all mathematics function
*/

#include "proto.h"

char *my_strcat(char *dest, char const *src)
{
    int length;
    int i;

    length = 0;
    i = 0;
    while (dest[length])
        length++;
    while (src[i]) {
        dest[length] = src[i];
        length++;
        i++;
    }
    dest[length] = 0;
    return (dest);
}

int my_sqrt(int nb)
{
    int result = 0;

    if (nb < 0)
        return (0);
    for (result = 0; result * result != nb; result++) {
        if (result > nb)
            return (0);
    }
    return (result);
}

char **mem_alloc_2d_array(int size_x, int size_y)
{
    char **str = malloc(sizeof(char *) * (size_y + 1));

    if (str == NULL)
        exit(84);
    for (int i = 0; i < size_y; i++) {
        str[i] = malloc(sizeof(char) * (size_x + 1));
        for (int j = 0; j < size_x; j ++)
            str[i][j] = '\0';
        if (str[i] == NULL)
            exit(84);
    }
    return (str);
}

int my_pow(int nb, int p)
{
    if (p > 0)
        nb *= my_pow(nb, p - 1);
    else if (p == 0)
        return (1);
    else
        return (0);
    return (nb);
}

char *load_file_in_mem(char const *filepath)
{
    char *buffer;
    struct stat size;
    int security = -1;
    int file_description = open(filepath, O_RDONLY);

    if (file_description == -1) {
        write(2, "Files doesn't exist", 20);
        return (NULL);
    }
    stat(filepath, &size);
    buffer = malloc(size.st_size + 1);
    if (buffer == NULL)
        exit(84);
    security = read(file_description, buffer, size.st_size);
    if (security <= 0) {
        write(2, "Read is impossible", 18);
        return (NULL);
    }
    buffer[security] = '\0';
    close(file_description);
    return (buffer);
}