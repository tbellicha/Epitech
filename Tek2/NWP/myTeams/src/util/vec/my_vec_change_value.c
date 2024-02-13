/*
** EPITECH PROJECT, 2022
** MyTeams - LibMy Excerpt
** File description:
** Change a value
*/

#include "vec.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

my_vec_err_t my_vec_change_value(my_vec_t *vec, void *new_value, size_t index)
{
    assert(vec != NULL);
    assert(new_value != NULL);
    if (index >= vec->length)
        return MY_VEC_OUT_OF_BOUNDS;
    memcpy(((char *)vec->data) + vec->elem_size * index, new_value,
        vec->elem_size);
    return MY_VEC_OK;
}
