/*
** EPITECH PROJECT, 2022
** MyTeams - LibMy Excerpt
** File description:
** Flushes the elements of a vector
*/

#include "vec.h"

#include <assert.h>

void my_vec_clear(my_vec_t *vec, void (*elem_free)(void *))
{
    assert(vec != NULL);
    if (elem_free != NULL) {
        size_t len = vec->length;

        for (size_t i = 0; i < len; ++i)
            (*elem_free)(my_vec_get(vec, i));
    }
    vec->length = 0;
}
