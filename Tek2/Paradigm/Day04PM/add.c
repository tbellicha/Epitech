/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD04pm-tanguy.bellicha
** File description:
** main
*/

#include "int_list.h"
#include <stdio.h>
#include <stdlib.h>

bool int_list_add_elem_at_front(int_list_t *front_ptr, int elem)
{
    int_list_t new_node = (int_list_t) malloc(sizeof(int_list_t));

    if (new_node != NULL) {
        new_node->value = elem;
        new_node->next = (*front_ptr);
        (*front_ptr) = new_node;
        return (true);
    }
    return (false);
}

bool int_list_add_elem_at_back(int_list_t *front_ptr, int elem)
{
    int_list_t new_node = (int_list_t) malloc(sizeof(int_list_t));
    int_list_t current_node;

    if (new_node == NULL)
        return (false);
    new_node->value = elem;
    new_node->next = NULL;
    if (*front_ptr == NULL)
        return (int_list_add_elem_at_front(front_ptr, elem));
    current_node = *front_ptr;
    while (current_node->next != NULL)
        current_node = current_node->next;
    current_node->next = new_node;
    return (true);
}

bool int_list_add_elem_at_position(int_list_t *front_ptr, int elem, \
unsigned int position)
{
    int_list_t new_node = (int_list_t) malloc(sizeof(int_list_t));
    int_list_t current_node = *front_ptr;

    if (position == 0)
        return (int_list_add_elem_at_front(front_ptr, elem));
    if (position == int_list_get_size(*front_ptr))
        return (int_list_add_elem_at_back(front_ptr, elem));
    if (position > int_list_get_size(*front_ptr))
        return (false);
    new_node->value = elem;
    new_node->next = NULL;
    for (int i = 0; i < ((int) position - 1); i++)
        current_node = current_node->next;
    new_node->next = current_node->next;
    current_node->next = new_node;
    return (true);
}
