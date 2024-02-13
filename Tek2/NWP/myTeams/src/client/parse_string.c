/*
** EPITECH PROJECT, 2022
** Project
** File description:
** parse_string
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>

ssize_t parse_string(char *str, char *error_message)
{
    char *second = NULL;

    if (!str[0]) {
        puts(error_message);
        return -1;
    }
    if (str[0] != '"') {
        puts("Parameters must be surrounded by quotes.");
        return -1;
    }
    second = strchr(&str[1], '"');
    if (second == NULL) {
        puts("Missing closing quote.");
        return -1;
    }
    return second - str - 1;
}
