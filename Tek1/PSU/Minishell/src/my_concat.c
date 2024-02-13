/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-tanguy.bellicha
** File description:
** string.c
*/

#include "minishell.h"

char *str_concat(s_shell *shell, char *str)
{
    char **path = shell->path;
    int i = 0;
    char *cmd = NULL;

    while (path[i]) {
        cmd = malloc(my_strlen(path[i]) + my_strlen(str) + 2);
        *cmd = 0;
        my_strcat(cmd, path[i]);
        my_strcat(cmd, "/");
        my_strcat(cmd, str);
        if (access(cmd, F_OK && X_OK) == 0)
            return (cmd);
        free(cmd);
        i++;
    }
    return (NULL);
}