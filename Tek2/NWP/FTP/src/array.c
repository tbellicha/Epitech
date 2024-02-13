/*
** EPITECH PROJECT, 2022
** Projects
** File description:
** array
*/

#include "ftp.h"

int get_array_size(const char **array)
{
    int i = 0;

    while (array[i])
        i++;
    return i;
}

void free_array(char **array)
{
    int i = 0;

    while (array[i])
        free(array[i++]);
    free(array);
}

char **str_to_word_array(char *str, char *sep)
{
    int i = 0;
    char **tab = malloc(sizeof(char *));
    char *before_sep = strtok(str, sep);

    if (!str || !tab || !before_sep)
        return NULL;
    while (1) {
        tab[i++] = strdup(before_sep);
        tab = realloc(tab, (sizeof(char *) * (i + 1)));
        before_sep = strtok(NULL, sep);
        if (!before_sep){
            tab[i] = before_sep;
            break;
        }
    }
    free(before_sep);
    return tab;
}
