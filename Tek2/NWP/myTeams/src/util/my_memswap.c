/*
** EPITECH PROJECT, 2021
** MyTeams - LibMy Excerpt
** File description:
** Swaps the contents of two pointers
*/

#include "util.h"

#include <assert.h>
#include <stddef.h>

void my_memswap(void *restrict a, void *restrict b, size_t size)
{
    assert(a != b);
    for (size_t i = 0; i < size; ++i) {
        ((char *)a)[i] = ((char *)a)[i] ^ ((char *)b)[i];
        ((char *)b)[i] = ((char *)a)[i] ^ ((char *)b)[i];
        ((char *)a)[i] = ((char *)a)[i] ^ ((char *)b)[i];
    }
}
