/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD04am-tanguy.bellicha
** File description:
** sort
*/

#include <stdlib.h>
#include <stdio.h>

int cmpint(const void *a, const void *b)
{
    return (*(int *) a - *(int *) b);
}

int cmpfunc(const void *a, const void *b)
{
    return (*(char *) a - *(char *) b);
}

void sort_int_array(int *array, size_t nmemb)
{
    qsort(array, nmemb, sizeof(int), cmpint);
}

void sort_array(void *array, size_t nmemb, size_t size, \
int (*compar)(const void *, const void *))
{
    qsort(array, nmemb, size, cmpfunc);
}
