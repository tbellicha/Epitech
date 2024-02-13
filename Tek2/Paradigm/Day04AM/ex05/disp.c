/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD04am-tanguy.bellicha
** File description:
** disp
*/

#include <stdio.h>

void disp_int_array(const int *array, size_t nmemb)
{
    for (int i = 0; i < nmemb; i++)
        printf("%d\n", array[i]);
}

void disp_array(const void *array, size_t nmemb, size_t size, \
void (*print)(const void *))
{
    for (int i = 0; i < nmemb; i++)
        (*print)(array + (i * size));
}
