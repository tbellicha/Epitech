/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-BSQ-tanguy.bellicha
** File description:
** errors
*/

#include <stdlib.h>
#include "my.h"
#include <unistd.h>

int check_char(char **tab, int i, int k, int nb_column)
{
    if (tab[k][i] == '\n' && i != nb_column)
        return (84);
    if (tab[k][i] != '\n' && tab[k][i] != 'o' && \
    tab[k][i] != '.' && tab[k][i])
        return (84);
    return (0);
}

int compare_linesize_to_first(char *line,  int first_line_size)
{
    if (my_strlen(line) != first_line_size)
        return (84);
    return (0);
}

int check_map(char **tab, int nb_column, int nb_line)
{
    int i = 0;
    int k = 0;
    int first_line_size = my_strlen(tab[0]);

    while (tab[k][i]) {
        if (check_char(tab, i, k, nb_column) == 84)
            return (84);
        if ((k + 1) == nb_line && i == nb_column)
            return (compare_linesize_to_first(tab[k], first_line_size));
        if (i == nb_column) {
            k++;
            i = 0;
        }
        i++;
    }
    return (0);
}