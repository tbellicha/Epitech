/*
** EPITECH PROJECT, 2020
** mylist
** File description:
** mylist
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct linked_list
{
    void *data;
    struct linked_list *next;
} linked_list_t;