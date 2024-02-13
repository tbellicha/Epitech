/*
** EPITECH PROJECT, 2021
** my_str_to_word_tab.c
** File description:
** my str to word tab
*/

#include <stdlib.h>

int my_count_word(char *str, char sep)
{
    int nb;
    int i;

    i = 0;
    nb = 0;
    while (str[i]) {
        if (str[i] == sep && str[i + 1])
            nb++;
        i++;
    }
    return (nb + 1);
}

int word_len(char *str, char sep)
{
    int i;

    i = 0;
    while (str[i] && str[i] != sep)
        i++;
    return (i);
}

int skip_sep(int *ptr_i, char *str, char sep)
{
    while (str[*ptr_i] == sep)
        *ptr_i += 1;
    return (0);
}

char **my_str_to_word_tab_lines(char **t, char *s, char sep, int i)
{
    int j = 0;

    for (int k = 0; s[i];) {
        if (s[i] == sep) {
            k = skip_sep(&i, s, sep);
            j++;
        }
        t[j] = malloc(sizeof(char) * (word_len(s + i, sep) + 1));
        if (t[j] == NULL)
            return (NULL);
        while (s[i] != sep && s[i])
            t[j][k++] = s[i++];
        t[j][k] = 0;
    }
    t[j + 1] = 0;
    return (t);
}

char **my_str_to_word_tab(char *s, char sep)
{
    char **t;
    int i = 0;

    skip_sep(&i, s, sep);
    t = malloc(sizeof(char *) * (my_count_word(s, sep) + 2));
    if (t == NULL)
        return (NULL);
    t = my_str_to_word_tab_lines(t, s, sep, i);
    return (t);
}
