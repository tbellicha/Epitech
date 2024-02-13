/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-tanguy.bellicha
** File description:
** .h
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

#include "my.h"

typedef struct t_shell {
    char **base_env;
    char **current_env;
    char **input;
    char **path;
    char *current_cd;
    char *previous_cd;
    int ret;

    char *line;
    size_t length;
    ssize_t read;
} s_shell;

void start_unsetenv(s_shell *shell, int start);
void start_setenv(s_shell *shell);
int find_in_env(s_shell *shell, char *to_find);

void my_put_tab(char **arg);
char *get_str_upto_char(char *str, char c);

int start_cd(s_shell *shell);
void simple_cd(s_shell *shell, char *dir, char *cd);
void path_cd(s_shell *shell, char *dir, char *cd);
void previous_cd_cd(s_shell *shell);

int my_env_switch(s_shell *shell);
int my_simple_switch(s_shell *shell);
int my_global_switch(s_shell *shell);
void run_shell(s_shell *shell);
char *str_concat(s_shell *shell, char *str);

int count_words(char *str, char *delims);
char **my_strtok(char *str, char *list_parser);

char **copy_tab(char **src_tab, int remove);
int get_tab_size(char **tab);

char *check_is_executable(s_shell *shell);
void my_print_error(int status);

#endif /* !MINISHELL_H_ */