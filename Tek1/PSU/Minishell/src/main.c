/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-tanguy.bellicha
** File description:
** main
*/

#include "minishell.h"

void get_valid_path(s_shell *shell)
{
    int i = 0;
    char *path = NULL;

    while (shell->base_env[i] && my_strncmp(shell->base_env[i], "PATH=", 5))
        i++;
    if (shell->base_env[i]) {
        path = shell->base_env[i] + 5;
        shell->path = my_str_to_word_array(path, ":\n");
    }
}

int initialize_shell(s_shell *shell, char **env) {
    if (shell == NULL)
        return (0);
    shell->current_cd = getcwd(NULL, 0);
    shell->previous_cd = NULL;
    shell->base_env = malloc(sizeof(char *) * get_tab_size(env));
    shell->base_env = copy_tab(env, -1);
    shell->current_env = malloc(sizeof(char *) * get_tab_size(env));
    shell->current_env = copy_tab(env, -1);
    shell->ret = 0;
    shell->line = NULL;
    get_valid_path(shell);
    return (1);
}

char *check_is_executable(s_shell *shell)
{
    struct stat filestat;

    if (!stat(shell->input[0], &filestat)) {
        if (S_ISDIR(filestat.st_mode)) {
            my_printf("%s: Permission denied.\n", shell->input[0]);
            return (0);
        }
        if (access(shell->input[0], X_OK) == 0)
            return (shell->input[0]);
    }
    return (0);

}

void my_print_error(int status)
{
    int sig = WTERMSIG(status);

    if (sig == 11) {
        if (WCOREDUMP(status))
            my_printf("Segmentation fault (core dumped)\n");
        else
            my_printf("Segmentation fault\n");
    }
    if (sig == 8)
        my_printf("Floating Point Exception\n");
}

int main(int argc, char **argv, char **env)
{
    s_shell *shell = malloc(sizeof(s_shell));

    (void)argv;
    if (!initialize_shell(shell, env) || argc != 1)
        return (84);
    while (1) {
        if (isatty(0))
            my_printf("$> ");
        run_shell(shell);
    }
    return (0);
}