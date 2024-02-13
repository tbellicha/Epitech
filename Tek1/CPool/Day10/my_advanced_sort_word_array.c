/*
** EPITECH PROJECT, 2020
** my_advanced_sort_word_array
** File description:
** my_advanced_sort_word_array
*/

#include "my.h"
#include <unistd.h>

static int check_swap(char **tab, int i, int (*cmp)(char const *, char const *))
{
    if (i > 0 && cmp(tab[i], tab[i - 1]) < 0)
        return (1);
    return (0);
}

int my_advanced_sort_word_array(char **tab, int (*cmp)\
(char const *, char const *))
{
    int i = 0;
    char *tempo = 0;

    while (tab[i] != 0) {
        if (check_swap(tab, i, cmp) == 1) {
            tempo = my_strdup(tab[i]);
            tab[i] = my_strdup(tab[i - 1]);
            tab[i - 1] = my_strdup(tempo);
            i -= 2;
        }
        i++;
    }
    return (0);
}