/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD04pm-tanguy.bellicha
** File description:
** get
*/

#include "int_list.h"
#include <stdlib.h>

int int_list_get_elem_at_front(int_list_t list)
{
    if (list == NULL)
        return (0);
    return (list->value);
}

int int_list_get_elem_at_back(int_list_t list)
{
    if (list == NULL)
        return (0);
    while (list->next != NULL)
        list = list->next;
    return (list->value);
}

int int_list_get_elem_at_position(int_list_t list, \
unsigned int position)
{
    if (list == NULL)
        return (0);
    if (position == 0)
        return (int_list_get_elem_at_front(list));
    for (int i = 0; i < ((int) position - 1); i++)
        list = list->next;
    return (list->value);
}
