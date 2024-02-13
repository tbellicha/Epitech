/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD04pm-tanguy.bellicha
** File description:
** infos
*/

#include "int_list.h"
#include <stdio.h>

unsigned int int_list_get_size(int_list_t list)
{
    int size = 0;

    while (list) {
        size++;
        list = list->next;
    }
    return (size);
}

bool int_list_is_empty(int_list_t list)
{
    if (int_list_get_size (list) >= 1)
        return (false);
    return (true);
}

void int_list_dump(int_list_t list)
{
    while (list != NULL) {
        printf("%d\n", list->value);
        list = list->next;
    }
}
