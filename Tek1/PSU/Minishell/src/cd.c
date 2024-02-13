/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-tanguy.bellicha
** File description:
** cd
*/

#include "minishell.h"

void simple_cd(s_shell *shell, char *dir, char *cd)
{
    int count = 0;
    int i = 0;

    dir = getcwd(NULL, 0);
    shell->previous_cd = dir;
    while (dir[i] && count != 3) {
        if (dir[i] == '/')
            count++;
        if (count == 3)
            my_strncpy(cd, dir, i);
        i++;
    }
    chdir(cd);
}

void path_cd(s_shell *shell, char *dir, char *cd)
{
    dir = getcwd(NULL, 0);
    if (shell->input[1][my_strlen(shell->input[1]) - 1] != '/') {
        cd = malloc(sizeof(char) *  (my_strlen(shell->input[1] + 1)));
        cd = my_strdup(shell->input[1]);
        cd[my_strlen(cd)] = '/';
        cd[my_strlen(cd) + 1] = 0;
    }
    if (chdir(shell->input[1]) == -1) {
        my_printf("%s: No such file or directory.\n", shell->input[1]);
        return ;
    }
    shell->previous_cd = my_strdup(dir);
}

void previous_cd_cd(s_shell *shell)
{
    char *tempo = getcwd(NULL, 0);

    if (shell->previous_cd == NULL) {
        my_printf(": No such file or directory.\n");
        return ;
    }
    chdir(shell->previous_cd);
    shell->previous_cd = my_strdup(tempo);
    free(tempo);
}

int start_cd(s_shell *shell)
{
    char *dir = malloc(sizeof(char *));
    char *cd = malloc(sizeof(char *));

    if (shell->input[1] && shell->input[2]) {
        my_printf("cd: Too many arguments.\n");
        return (84);
    }
    if (shell->input[1] != NULL && my_strcmp(shell->input[1], "-"))
        path_cd(shell, dir, cd);
    if (!shell->input[1] || !my_strcmp(shell->input[1], "\12"))
        simple_cd(shell, dir, cd);
    if (shell->input[1] != NULL && !my_strcmp(shell->input[1], "-"))
        previous_cd_cd(shell);
    return (0);
}