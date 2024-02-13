/*
** EPITECH PROJECT, 2022
** MyTeams - LibMy Excerpt
** File description:
** Removes the last elements from a vec
*/

#include "util.h"
#include "vec.h"

#include <stdlib.h>
#include <string.h>

void my_vec_pop(my_vec_t *vec, void *dst)
{
    my_vec_pop_multiple(vec, dst, 1);
}

void my_vec_pop_multiple(my_vec_t *vec, void *dst, size_t count)
{
    count = MY_MIN(count, vec->length);
    if (!count)
        return;
    vec->length -= count;
    if (dst)
        memcpy(dst, ((char *)vec->data) + vec->length * vec->elem_size,
            count * vec->elem_size);
}
