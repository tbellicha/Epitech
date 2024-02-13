/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-johan.chrillesen
** File description:
** my_str_to_wordtab
*/

#include "solver.h"

int	count_words(char *str, char separator)
{
    int	i = 0;
    int	nb = 1;

    while (str[i]) {
        if (str[i] == separator)
            nb++;
        i++;
    }
    return (nb);
}

char **my_str_to_wordtab(char *str, char separator)
{
    char **tab = NULL;
    int	i = 0;
    int	j = 1;

    if ((tab = \
        malloc((count_words(str, separator) + 1) * sizeof(char *))) == NULL)
        return (NULL);
    tab[count_words(str, separator)] = NULL;
    tab[0] = str;
    while (str[i]) {
        if (str[i] == separator) {
            str[i++] = 0;
            tab[j] = &str[i];
            j++;
        }
        i++;
    }
    return (tab);
}

void my_show_wordtab(char **tab)
{
    int	line = 0;
    int column = 0;

    while (tab[line]) {
        column = 0;
        while (tab[line][column]) {
            if (tab[line][column] == 'X')
                printf("X");
            column++;
        }
        line++;
    }
}
