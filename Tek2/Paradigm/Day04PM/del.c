/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD04pm-tanguy.bellicha
** File description:
** del
*/

#include "int_list.h"
#include <stdio.h>
#include <stdlib.h>

bool int_list_del_elem_at_front(int_list_t *front_ptr)
{
    if (*front_ptr == NULL)
        return (false);
    *front_ptr = (*front_ptr)->next;
    if (*front_ptr == NULL)
        return (false);
    return (true);
}

bool int_list_del_elem_at_back(int_list_t *front_ptr)
{
    int_list_t last_node;

    if (*front_ptr == NULL)
        return (false);
    if ((*front_ptr)->next == NULL) {
        *front_ptr = NULL;
        return (false);
    }
    last_node = *front_ptr;
    while (last_node->next->next != NULL)
        last_node = last_node->next;
    last_node->next = NULL;
    return (true);
}

bool int_list_del_elem_at_position(int_list_t *front_ptr, \
unsigned int position)
{
    int_list_t prev_node;
    int_list_t current_node;

    if (position == 0 || *front_ptr == NULL)
        return (int_list_del_elem_at_front(front_ptr));
    else if (position == (int_list_get_size(*front_ptr) - 1))
        return (int_list_del_elem_at_back(front_ptr));
    current_node = *front_ptr;
    prev_node = current_node;
    while (current_node->next != NULL && (int) position > 0) {
        prev_node = current_node;
        current_node = current_node->next;
        position--;
    }
    if ((int) position != 0 || current_node->next == NULL)
        return (false);
    prev_node->next = current_node->next;
    free(current_node);
    return (true);
}

void int_list_clear(int_list_t *front_ptr)
{
    while (*front_ptr != NULL)
        int_list_del_elem_at_front(front_ptr);
    free(*front_ptr);
}
