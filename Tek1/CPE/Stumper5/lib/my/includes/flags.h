/*
** EPITECH PROJECT, 2020
** flags.h
** File description:
** struct for flags
*/

#include <stdarg.h>

#ifndef FLAGS_H_
#define FLAGS_H_

typedef struct which_flag
{
    char flag;
    int (*fonc_ptr)(va_list args, ...);
} which_flag_t;

#endif
