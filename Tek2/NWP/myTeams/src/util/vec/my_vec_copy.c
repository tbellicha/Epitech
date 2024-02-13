/*
** EPITECH PROJECT, 2022
** MyTeams - LibMy Excerpt
** File description:
** Copies a vector into an other
*/

#include "vec.h"

#include <stdlib.h>
#include <string.h>

my_vec_err_t my_vec_copy(my_vec_t *dst, my_vec_t const *src)
{
    if (src->length > 0) {
        dst->data = malloc(src->length * src->elem_size);
        if (!dst->data)
            return MY_VEC_ALLOC;
        memcpy(dst->data, src->data, src->length * src->elem_size);
    } else {
        dst->data = NULL;
    }
    dst->length = src->length;
    dst->capacity = src->length;
    dst->elem_size = src->elem_size;
    return MY_VEC_OK;
}

my_vec_err_t my_vec_copy_into(my_vec_t *dst, my_vec_t const *src)
{
    if (dst->capacity < src->length || dst->elem_size != src->elem_size) {
        my_vec_free(dst, NULL);
        return my_vec_copy(dst, src);
    }
    if (src->length)
        memcpy(dst->data, src->data, src->length * src->elem_size);
    dst->length = src->length;
    return MY_VEC_OK;
}
