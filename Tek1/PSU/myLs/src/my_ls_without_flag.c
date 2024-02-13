/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myls-tanguy.bellicha
** File description:
** my_ls_without_flags
*/

#include "my.h"

void my_put_tab(char **tab, char *parser, int limit)
{
    int i = 0;

    if (limit > 1)
        limit--;
    while (tab[i] && (i <= limit || limit == 0)) {
        my_putstr(tab[i]);
        if (tab[i + 1])
            my_putstr(parser);
        else
            my_putchar('\n');
        if (i != 0 && i == limit)
            my_putchar('\n');
        i++;
    }
}

int my_ls_without_flag(DIR *directory)
{
    struct dirent *dir;
    char **tab_dir_files = malloc(sizeof(char *));
    int i = 0;

    while ((dir = readdir(directory)))
        if (dir->d_name[0] != '.')
            tab_dir_files[i++] = dir->d_name;
    my_put_tab(sort_alphabetically(tab_dir_files), "  ", 0);
    return (0);
}