/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-pushswap-tanguy.bellicha
** File description:
** push_and_pop
*/

#include "my.h"

s_lists *put_in_a(s_lists *lists)
{
    if (lists->size2 > 0) {
        lists->list_a[lists->size1] = lists->list_b[0];
        lists->size1++;
        rotate_ra(lists, 0);
        rotate_b(lists, 0);
        lists->size2--;
        my_putstr(" pa");
    }
    return (lists);
}

s_lists *put_in_b(s_lists *lists, int space)
{
    if (lists->size1 > 0) {
        lists->list_b[lists->size2] = lists->list_a[0];
        lists->size2++;
        if (lists->size2 > 2) {
            rotate_rb(lists, 0);
            space = 1;
        }
        rotate_a(lists, 0);
        lists->size1--;
        if (space == 0)
            my_putstr("pb");
        else
            my_putstr(" pb");
    }
    return (lists);
}

s_lists *switch_a(s_lists *lists, int space)
{
    int tempo = 0;

    if (lists->size1 > 1) {
        tempo = lists->list_a[0];
        lists->list_a[0] = lists->list_a[1];
        lists->list_a[1] = tempo;
        if (space == 0)
            my_putstr("sa");
        else
            my_putstr(" sa");
    }
    return (lists);
}

s_lists *switch_b(s_lists *lists)
{
    int tempo = 0;

    if (lists->size2 > 1) {
        tempo = lists->list_b[0];
        lists->list_b[0] = lists->list_b[1];
        lists->list_b[1] = tempo;
        my_putstr(" sb");
    }
    return (lists);
}