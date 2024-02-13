/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myls-tanguy.bellicha
** File description:
** control
*/

#include "my.h"

s_my_ls detect_flags(s_my_ls params, char *str)
{
    int i = 1;

    if (str[0] == '-')
        while (str[i]) {
            params = switch_param(params, str[i]);
            i++;
        }
    if (i == 1)
        params.valid = 0;
    return (params);
}

int get_type(char *str)
{
    int directory_value = 1;
    int flag_value = 0;
    int cannot_read = -1;
    DIR *dir;

    if (str[0] == '-' && str[1])
        return (flag_value);
    if (!(dir = opendir(str)))
        return (cannot_read);
    else {
        closedir(dir);
        return (directory_value);
    }
    closedir(dir);
    return (-2);
}

int print_error_access(int value, char *arg)
{
    if (value == -1) {
        my_printf("my_ls: cannot access '%s':", arg);
        my_printf(" No such file or directory\n");
    }
    return (value);
}