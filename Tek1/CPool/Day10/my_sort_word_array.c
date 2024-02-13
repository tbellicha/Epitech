/*
** EPITECH PROJECT, 2020
** my_sort_word_array
** File description:
** my_sort_word_array
*/

#include "my.h"
#include <unistd.h>

static int check_swap(char **tab, int i)
{
    int k = 0;

    if (i > 0 && tab[i][k] < tab[i - 1][k])
        return (1);
    else if (i > 0 && tab[i][k] == tab[i - 1][k]) {
        while (tab[i][k] == tab[i - 1][k])
            k++;
        if (tab[i][k] < tab[i - 1][k])
            return (1);
        else
            return (0);
    }
    return (0);
}

int my_sort_word_array(char **tab)
{
    int i = 0;
    char *tempo = 0;

    while (tab[i] != 0) {
        if (check_swap(tab, i) == 1) {
            tempo = my_strdup(tab[i]);
            tab[i] = my_strdup(tab[i - 1]);
            tab[i - 1] = my_strdup(tempo);
            i -= 2;
        }
        i++;
    }
    return (0);
}