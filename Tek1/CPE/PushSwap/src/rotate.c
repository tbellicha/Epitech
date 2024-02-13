/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-pushswap-tanguy.bellicha
** File description:
** rotate_int_array
*/

#include "my.h"

s_lists *rotate_a(s_lists *lists, int display)
{
    int tempo = lists->list_a[0];

    if (lists->size1 > 1) {
        for (int i = 0; i < (lists->size1 - 1); i++)
            lists->list_a[i] = lists->list_a[i + 1];
        lists->list_a[lists->size1 - 1] = tempo;
        if (display == 0)
            return (lists);
        my_putstr(" ra");
    }
    return (lists);
}

s_lists *rotate_b(s_lists *lists, int display)
{
    int tempo = lists->list_b[0];

    if (lists->size2 > 1) {
        for (int i = 0; i < (lists->size2 - 1); i++)
            lists->list_b[i] = lists->list_b[i + 1];
        lists->list_b[lists->size2 - 1] = tempo;
        if (display == 0)
            return (lists);
        my_putstr(" rb");
    }
    return (lists);
}

s_lists *rotate_ra(s_lists *lists, int display)
{
    int tempo = lists->list_a[lists->size1 - 1];

    if (lists->size1 > 1) {
        for (int i = (lists->size1 - 1); i > 0; i--)
            lists->list_a[i] = lists->list_a[i - 1];
        lists->list_a[0] = tempo;
        if (display == 0)
            return (lists);
        my_putstr(" rra");
    }
    return (lists);
}

s_lists *rotate_rb(s_lists *lists, int display)
{
    int tempo = lists->list_b[lists->size2 - 1];

    if (lists->size2 > 1) {
        for (int i = (lists->size2 - 1); i > 0; i--)
            lists->list_b[i] = lists->list_b[i - 1];
        lists->list_b[0] = tempo;
        if (display == 0)
            return (lists);
        my_putstr(" rrb");
    }
    return (lists);
}