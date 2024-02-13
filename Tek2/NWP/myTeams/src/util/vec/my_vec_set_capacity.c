/*
** EPITECH PROJECT, 2022
** MyTeams - LibMy Excerpt
** File description:
** Sets the capacity of a vec by growing or shrinking it.
*/

#include "vec.h"

#include <stdlib.h>

my_vec_err_t my_vec_set_capacity(
    my_vec_t *vec, size_t new_capacity, void (*elem_free)(void *))
{
    size_t len = vec->length;
    size_t elem_size = vec->elem_size;
    void *new_data;

    if (elem_free)
        for (size_t i = new_capacity; i < len; ++i)
            (*elem_free)(my_vec_get(vec, i));
    new_data = realloc(vec->data, new_capacity * elem_size);
    if (new_capacity && !new_data)
        return MY_VEC_ALLOC;
    if (new_capacity < len)
        vec->length = new_capacity;
    vec->capacity = new_capacity;
    vec->data = new_data;
    return MY_VEC_OK;
}
