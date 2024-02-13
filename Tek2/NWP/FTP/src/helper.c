/*
** EPITECH PROJECT, 2022
** Projects
** File description:
** helper
*/

#include "ftp.h"

int print_helper(const char *arg)
{
    if (!strcmp(arg, HELPER_CMD)) {
        printf("USAGE: ./myftp port path\n");
        printf("\tport\t");
        printf("is the port number on which the server socket listens\n");
        printf("\tpath\t");
        printf("is the path to the home directory for the Anonymous user\n");
        return RETURN_HELPER;
    }
    return RETURN_FAILURE;
}
