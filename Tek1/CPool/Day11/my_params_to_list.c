/*
** EPITECH PROJECT, 2020
** my_params_to_list
** File description:
** my_params_to_list
*/

#include "my.h"
#include "mylist.h"

linked_list_t *my_put_in_list(void *data, linked_list_t *list)
{
    linked_list_t *list_sup;

    list_sup = malloc(sizeof(linked_list_t));
    list_sup->data = data;
    list_sup->next = list;
    return (list_sup);
}

linked_list_t *my_params_to_list(int ac, char const * const *av)
{
    linked_list_t *list;
    int i;

    list = NULL;
    for (i = 0; i < ac; i++)
        list = my_put_in_list(av[i], list);
    return (list);
}