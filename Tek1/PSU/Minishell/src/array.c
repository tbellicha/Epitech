/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-tanguy.bellicha
** File description:
** array
*/

#include "minishell.h"

void my_put_tab(char **arg)
{
    int i = 0;

    while (arg[i]) {
        my_putstr(arg[i]);
        my_putchar('\n');
        i++;
    }
}

int get_tab_size(char **tab)
{
    int i = 0;

    if (!tab[i] || tab == NULL)
        return (0);
    while (tab[i])
        i++;
    return (i);
}

int my_char_is_in_string(char const *str, char c)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == c)
            return (1);
    }
    return (0);
}

char **copy_tab(char **src_tab, int remove)
{
    int i_src = 0;
    int i_new = 0;
    char **new_tab = malloc(sizeof(char *) * (get_tab_size(src_tab) + 1));

    while (src_tab[i_src]) {
        new_tab[i_new] = my_strdup(src_tab[i_src]);
        i_new++;
        i_src++;
        if (i_src == remove )
            i_src++;
    }
    new_tab[i_new] = 0;
    return (new_tab);
}

char *get_str_upto_char(char *str, char c)
{
    int i = 0;
    char *found = NULL;

    while (str[i] != c) {
        i++;
    }
    if (i == 0)
        return (NULL);
    found = malloc(sizeof(char) * (i + 1));
    found = my_strncpy(found, str, i);
    return (found);
}