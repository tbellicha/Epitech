/*
** EPITECH PROJECT, 2021
** MyTeams - LibMy Excerpt
** File description:
** Initializes hash maps
*/

#include <stdlib.h>

void *my_calloc(size_t nmemb, size_t size)
{
    if (nmemb == 0)
        return NULL;
    return calloc(nmemb, size);
}
