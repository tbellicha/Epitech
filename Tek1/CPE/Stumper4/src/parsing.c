/*
** EPITECH PROJECT, 2025
** stump_4
** File description:
** Created by hjulien,
*/

#include "pokemon.h"

char *load_file(char const *filepath)
{
    char *file;
    unsigned int fd;
    struct stat buf;
    int test;

    test = stat(filepath, &buf);
    if (test != 0)
        return (NULL);
    file = my_calloc_char((buf.st_size + 1), '\0');
    if (!file)
        return (NULL);
    fd = open(filepath, O_RDONLY);
    test = read(fd, file, buf.st_size);
    if (test != buf.st_size)
        return (NULL);
    file[buf.st_size] = '\0';
    close(fd);
    return (file);
}

int list_files(pokedex_t *pokedex, char *pathname)
{
    struct dirent *dirs;
    DIR *dir;
    char *pathfile = NULL;

    dir = opendir(pathname);
    if (!dir)
        return (-1);
    while ((dirs = readdir(dir)) != NULL) {
        if (!my_strcmp(dirs->d_name, ".") || !my_strcmp(dirs->d_name, ".."))
            continue;
        pathfile = malloc(sizeof(char) * \
        (my_strlen(dirs->d_name) + my_strlen(pathname) + 1));
        pathfile = my_strcat(pathfile, pathname);
        pathfile = my_strcat(pathfile, dirs->d_name);
        manage_file_content(pokedex, load_file(pathfile));
    }
    closedir(dir);
    return (0);
}
