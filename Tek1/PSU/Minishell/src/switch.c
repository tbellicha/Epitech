/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-tanguy.bellicha
** File description:
** switch
*/

#include "minishell.h"

int my_simple_switch(s_shell *shell)
{
    if (!my_strcmp(shell->input[0], "exit")) {
        if (shell->input[1] && shell->input[2]) {
            my_printf("exit: Expression Syntax.\n");
            exit(1);
        }
        my_printf("exit\n");
        if (shell->input[1])
            exit(my_getnbr(shell->input[1]) % 256);
        exit(0);
    }
    if (!my_strcmp(shell->input[0], "pwd")) {
        my_printf("%s\n", getcwd(NULL, 0));
        return (1);
    }
    return (0);
}

int my_global_switch(s_shell *shell)
{
    if (!my_strcmp(shell->line, "\n"))
        return (1);
    shell->input = my_str_to_word_array(shell->line, " \t\n");
    if (my_env_switch(shell))
        return (1);
    if (my_simple_switch(shell))
        return (1);
    if (!my_strcmp(shell->input[0], "cd")) {
        start_cd(shell);
        return (1);
    }
    return (0);
}

char *run_command(s_shell *shell)
{
    char *str = malloc(sizeof(char *));

    str = shell->input[0];
    str = str_concat(shell, str);
    if (str == NULL) {
        str = check_is_executable(shell);
        if (str == NULL) {
            my_printf("%s: Command not found.\n", shell->input[0]);
            return (NULL);
        }
    }
    return (str);
}

void run_shell(s_shell *shell)
{
    int pid = 0;
    int status;
    char *str = NULL;

    shell->read = getline(&shell->line, &shell->length, stdin);
    if (shell->read == -1)
        my_printf("exit\n");
    if (shell->read == -1 || (my_strlen(shell->line) == 1 && !isatty(0)))
        exit(0);
    if (my_global_switch(shell) == 1)
        return ;
    str = run_command(shell);
    pid = fork();
    if (pid == 0) {
        execve(str, shell->input, shell->base_env);
        my_printf("%s: Exec format error. Wrong Architecture.\n", str);
        exit(0);
    }
    waitpid(pid, &status, 0);
    if (WIFSIGNALED(status))
        my_print_error(status);
}