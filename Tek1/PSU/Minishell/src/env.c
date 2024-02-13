/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-tanguy.bellicha
** File description:
** env
*/

#include "minishell.h"

int my_env_switch(s_shell *shell)
{
    if (!my_strcmp(shell->input[0], "env") || \
    (!my_strcmp( shell->input[0], "setenv"))) {
        my_put_tab(shell->current_env);
        return (1);
    } else if (!my_strcmp(shell->input[0], "unsetenv")) {
        start_unsetenv(shell, 1);
        return (1);
    } else if (!my_strcmp(shell->input[0], "setenv") && shell->input[1]) {
        if (find_in_env(shell, shell->input[1]) != -1)
            start_unsetenv(shell, 1);
        start_setenv(shell);
        return (1);
    }
    return (0);
}

void start_setenv(s_shell *shell)
{
    char **new_env = NULL;
    int size = 0;

    new_env = malloc(sizeof(char *) * (get_tab_size(shell->current_env) + 2));
    new_env = copy_tab(shell->current_env, -1);
    new_env[get_tab_size(new_env)] = my_strdup(shell->input[1]);
    size = get_tab_size(new_env);
    new_env[size - 1] = my_strcat(new_env[size - 1], "=");
    if (shell->input[2])
        new_env[size - 1] = my_strcat(new_env[size - 1], shell->input[2]);
    new_env[size] = 0;
    shell->current_env = copy_tab(new_env, -1);
}

int find_in_env(s_shell *shell, char *to_find)
{
    int i = 0;

    while (shell->current_env[i]) {
        if (!my_strcmp(to_find, get_str_upto_char(shell->current_env[i], '=')))
            return (i);
        i++;
    }
    return (-1);
}

void start_unsetenv(s_shell *shell, int start)
{
    if (!shell->input[1]) {
        my_printf("unsetenv: Too few arguments.\n");
        return;
    }
    while (shell->input[start]) {
        shell->current_env = \
        copy_tab(shell->current_env, find_in_env(shell, shell->input[start]));
        start++;
    }
}
