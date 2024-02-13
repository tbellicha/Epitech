/*
** EPITECH PROJECT, 2022
** Project
** File description:
** str_isnum
*/

#include "pano.h"

bool my_strisnum(char* str)
{
    for (int i = 0; str[i]; i++)
        if (!isdigit(str[i]))
            return false;
    return true;
}