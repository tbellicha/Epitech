/*
** EPITECH PROJECT, 2021
** LibMy - memory module
** File description:
** Reverses elements in the given array
*/

#include "util.h"

#include <assert.h>

void *my_memrev(void *mem, size_t nmemb, size_t size)
{
    size_t half_len = nmemb / 2;

    assert(size == 0 || mem != NULL);
    for (size_t i = 0; i < half_len; ++i)
        my_memswap((char *)mem + i * size,
            (char *)mem + (nmemb - (i + 1)) * size, size);
    return mem;
}
