/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-pushswap-tanguy.bellicha
** File description:
** lists
*/

#include "my.h"

s_lists *initialize_lists(int argc)
{
    s_lists *tempo = malloc(sizeof(*tempo));

    if (tempo == NULL)
        return (NULL);
    tempo->list_a = malloc(sizeof(int) * (argc - 1));
    if (tempo->list_a == NULL)
        return (free_malloc(tempo, 1));
    tempo->list_b = malloc(sizeof(int) * (argc - 1));
    if (tempo->list_b == NULL)
        return (free_malloc(tempo, 2));
    tempo->size1 = 0;
    tempo->size2 = 0;
    return (tempo);
}

s_lists *initialize_sort(s_lists *lists, int space)
{
    if ((lists->list_a[0] < lists->list_a[1] && lists->size1 > 1) || \
    (lists->list_a[0] > lists->list_a[1] && lists->size1 == 2)) {
        lists = switch_a(lists, space);
        space = 1;
        if (check_order_list(lists) && lists->size2 == 0)
            return (lists);
    }
    lists = put_in_b(lists, space);
    return (lists);
}

s_lists *add_in_listb(s_lists *lists)
{
    if (lists->list_a[0] < lists->list_a[1])
        lists = switch_a(lists, 1);
    put_in_b(lists, 1);
    if (lists->list_b[0] < lists->list_b[1])
        rotate_b(lists, 1);
    if (lists->list_b[lists->size2 - 1] > \
    lists->list_b[lists->size2 - 2] && lists->size2 > 1)
        lists = before_lastb_lower_than_lastb(lists);
    return (lists);
}

s_lists *before_lastb_lower_than_lastb(s_lists *lists)
{
    while (lists->list_b[lists->size2 - 1] > \
    lists->list_b[lists->size2 - 2] && lists->size2 > 1) {
        if (lists->size2 == 2)
            return (lists = switch_b(lists));
        lists = rotate_rb(lists, 1);
        lists = rotate_rb(lists, 1);
        lists = put_in_a(lists);
        if (check_order_list(lists) && lists->size2 == 0)
            return (lists);
        lists = rotate_b(lists, 1);
    }
    return (lists);
}

void sort_list(s_lists *lists)
{
    int space = 0;
    int end = 0;

    lists = initialize_sort(lists, space);
    while (lists->size1 > 0 && end == 0) {
        if (check_order_list(lists) && lists->size2 == 0)
            end = 1;
        lists = add_in_listb(lists);
    }
    while (lists->size2 > 0)
        put_in_a(lists);
    my_putchar('\n');
}