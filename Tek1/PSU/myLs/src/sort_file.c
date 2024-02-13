/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myls-tanguy.bellicha
** File description:
** sort_file
*/

#include "my.h"

char **sort_alphabetically(char **tab_dir_files)
{
    int i = 0;
    int k = 0;
    int nb = 0;

    while (tab_dir_files[nb])
        nb++;
    for (i = 0; i < nb; i++) {
        for (k = i + 1; k < nb; k++) {
            my_strcasecmp(tab_dir_files[i], tab_dir_files[k]) >= 0 ? \
            my_swap(&tab_dir_files[i], &tab_dir_files[k]) : 0;
        }
    }
    return (tab_dir_files);
}

char ***sort_alphabetically_triple(char ***ls, int nb_line, int order)
{
    int i = 0;
    int k = 0;
    char **tab = malloc(sizeof(char **) * nb_line);
    int i_line = nb_line;

    while (i_line > 0)
        tab[i++] = ls[--i_line][6];
    tab[i] = 0;
    if (order == 1)
        tab = sort_alphabetically(tab);
    if (order == -1)
        tab = sort_alphabetically_reversed(tab);
    i = 0;
    while (i < nb_line) {
        while (k < nb_line) {
            (tab[i] == ls[k][6]) ? ls[k] = is_need_swap(ls, tab, i , k) : 0;
            k++;
        }
        k = 0;
        i++;
    }
    return (ls);
}

char **sort_alphabetically_reversed(char **tab_dir_files)
{
    int i = 0;
    int k = 0;
    int nb = 0;

    while (tab_dir_files[nb])
        nb++;
    for (i = 0; i < nb; i++) {
        for (k = i + 1; k < nb; k++) {
            my_strcasecmp(tab_dir_files[i], tab_dir_files[k]) <= 0 ? \
            my_swap(&tab_dir_files[i], &tab_dir_files[k]) : 0;
        }
    }
    return (tab_dir_files);
}