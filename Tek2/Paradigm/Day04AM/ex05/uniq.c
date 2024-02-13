/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD04am-tanguy.bellicha
** File description:
** uniq
*/

#include <stddef.h>
#include <stdio.h>

int check_back(int *array, int i)
{
    for (int back = 0; back < i; back++)
        if (array[back] == array[i])
            return (0);
    return (1);
}

size_t uniq_int_array(int *array, size_t nmemb)
{
    int need_print = 0;
    size_t new_nmemb = nmemb;

    for (int i = 0; i < nmemb; i++) {
        need_print = 1;
        if (!check_back(array, i))
            new_nmemb--;
        else
            printf("%d\n", array[i]);
    }
    return (new_nmemb);
}
