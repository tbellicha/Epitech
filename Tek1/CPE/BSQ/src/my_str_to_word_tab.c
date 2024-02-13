/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-BSQ-tanguy.bellicha
** File description:
** my_str_to_wordtab
*/

#include <stdlib.h>
#include "my.h"

char **my_str_to_word_tab(char *str, char **tab, int count)
{
    int index_str = 0;
    int i = 0;
    int	k = 0;

    tab = malloc(sizeof(char **) * (count + 1));
    while (str[index_str]) {
        tab[i] = malloc(sizeof(char *) *\
        get_horizontal_length(str, index_str) + 1);
        while (str[index_str] != '\n') {
            tab[i][k] = str[index_str];
            k++;
            index_str++;
        }
        tab[i][k] = '\n';
        tab[i][k + 1] = 0;
        index_str++;
        i++;
        k = 0;
    }
    return (tab);
}
