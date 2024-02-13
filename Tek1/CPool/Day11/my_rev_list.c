/*
** EPITECH PROJECT, 2020
** my_rev_list
** File description:
** my_rev_list
*/

#include "mylist.h"

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *list;
    linked_list_t *tmp;
    linked_list_t *tmp_next_elem;

    list = *begin;
    tmp = NULL;
    while (list->next != 0) {
        tmp_next_elem = list->next;
        list->next = tmp;
        tmp = list;
        list = tmp_next_elem;
    }
    list->next = tmp;
    *begin = list;
    return (0);
}