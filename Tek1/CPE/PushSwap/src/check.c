/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-pushswap-tanguy.bellicha
** File description:
** check
*/

#include "my.h"

int check_args(int argc, char **argv)
{
    int i = 1;

    if (argc <= 1)
        return (84);
    while (argv[i]) {
        if (my_str_isnum(argv[i]))
            i++;
        else
            return (84);
    }
    return (0);
}

int check_order(char **argv)
{
    int i = 2;

    if (!argv[i])
        return (1);
    while (argv[i]) {
        if (my_getnbr(argv[i - 1]) > my_getnbr(argv[i]))
            return (0);
        i++;
    }
    return (1);
}

int check_order_list(s_lists *lists)
{
    int sorted = 1;

    for (int i = 0; i < lists->size1; i++) {
        if (lists->list_a[i - 1] > \
        lists->list_a[i])
            sorted = 0;
    }
    for (int i = 0; i < lists->size2; i++) {
        if (lists->list_b[i - 1] < \
        lists->list_b[i])
            sorted = 0;
    }
    return (sorted);
}

void *free_malloc(s_lists *tempo, int i)
{
    switch (i) {
        case 1:
            free(tempo);
            break;
        case 2:
            free(tempo->list_a);
            free(tempo);
            break;
        case 3:
            free(tempo->list_a);
            free(tempo->list_b);
            free(tempo);
            break;
    }
    return (NULL);
}