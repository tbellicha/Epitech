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
