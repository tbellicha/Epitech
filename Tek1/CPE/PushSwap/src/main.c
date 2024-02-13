/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-pushswap-tanguy.bellicha
** File description:
** main
*/

#include "my.h"

void free_all(s_lists *lists)
{
    if (lists == NULL)
        return;
    if (lists->list_a != NULL)
        free(lists->list_a);
    if (lists->list_b != NULL)
        free(lists->list_b);
    free(lists);
}

int main(int argc, char **argv)
{
    s_lists *lists = initialize_lists(argc);

    if (lists == NULL)
        return (84);
    if (check_args(argc, argv) == 84)
        return (84);
    if (check_order(argv) == 1) {
        my_putchar('\n');
        return (0);
    }
    argv = argv + 1;
    while (argv[lists->size1]) {
        lists->list_a[lists->size1] = my_getnbr(argv[lists->size1]);
        (lists->size1)++;
    }
    sort_list(lists);
    free_all(lists);
    return (0);
}