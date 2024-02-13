/*
** EPITECH PROJECT, 2021
** mathematics_functions.c
** File description:
** all mathematics function
*/

#include "proto.h"

bool my_str_search(char *str, char search, int *pos)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == search) {
            *pos = i;
            return (true);
        }
    }
    return (false);
}

bool my_nbr_search(int *str, int search, int size)
{
    for (int i = 0; i < size; i++) {
        if (str[i] == search) {
            return (true);
        }
    }
    return (false);
}