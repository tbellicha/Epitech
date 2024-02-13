/*
** EPITECH PROJECT, 2021
** error_manager.c
** File description:
** gestion of all errors
*/

#include "proto.h"

int my_puterror(char *error_message)
{
    write(2, "Error: ", 8);
    write(2, error_message, my_strlen(error_message));
    return (84);
}

int get_number_of_chars_before_new_line(char *str)
{
    int i = 0;

    while (str[i] && str[i] != '@')
        i++;
    return (i);
}

int check_length_and_second_arg(char *iteration, char *diese_pattern, \
char *point_pattern)
{
    char error_message[] = "The 2nd and the 3rd argument not same length";

    if (!my_str_isnum(iteration))
        return (my_puterror("The second argument should be a number.\n"));
    if (my_strlen(diese_pattern) != my_strlen(point_pattern)) {
        return (my_puterror(error_message));
    }
}

int check_characters(char *arg2, char *arg3)
{
    int i = -1;

    while (arg2[++i]) {
        if (arg2[i] != '#' && arg2[i] != '@' && arg2[i] != '.')
            return (my_puterror("Invalid character.\n"));
        if (arg3[i] != '.' && arg3[i] != '@')
            return (my_puterror("Invalid character.\n"));
    }
}

int check_error(int argc, char **argv)
{
    int i = -1;
    int count = 0;

    if (argc != 4)
        return (my_puterror("Invalid number of arguments.\n"));
    if (check_length_and_second_arg(argv[1], argv[2], argv[3]) == 84 || \
        check_characters(argv[2], argv[3]) == 84)
        return (84);
    (void) argc;
    while (argv[2][++i]) {
        if (argv[2][i] == '@' || argv[3][i] == '@')
            count++;
        if (argv[2][i] == '@' && argv[2][i] != argv[3][i])
            return (my_puterror("'@' are not at the same place.\n"));
    }
    if (count != get_number_of_chars_before_new_line(argv[2]) - 1)
        return (my_puterror("Invalid number of '@'.\n"));
    return (0);
}
