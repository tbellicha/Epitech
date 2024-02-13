/*
** EPITECH PROJECT, 2020
** my_list_size
** File description:
** my_list_size
*/

#include "mylist.h"

int my_list_size(linked_list_t const *begin)
{
    int size;

    for (size = 0; begin != 0; size++)
        begin = begin->next;
    return (size);
}