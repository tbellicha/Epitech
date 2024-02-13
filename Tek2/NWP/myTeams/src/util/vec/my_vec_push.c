/*
** EPITECH PROJECT, 2022
** MyTeams - LibMy Excerpt
** File description:
** Pushes an element to the back of the vec
*/

#include "util.h"
#include "vec.h"

#include <stdint.h>
#include <string.h>

my_vec_err_t my_vec_push(my_vec_t *vec, void *elem)
{
    return my_vec_push_multiple(vec, elem, 1);
}

my_vec_err_t my_vec_push_multiple(my_vec_t *vec, void *elems, size_t count)
{
    my_vec_err_t ret;

    ret = my_vec_reserve(vec, count);
    if (ret)
        return ret;
    memcpy(((char *)vec->data) + vec->elem_size * vec->length, elems,
        vec->elem_size * count);
    vec->length += count;
    return MY_VEC_OK;
}
