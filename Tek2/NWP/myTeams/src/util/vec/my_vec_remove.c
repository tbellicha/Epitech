/*
** EPITECH PROJECT, 2022
** MyTeams - LibMy Excerpt
** File description:
** Removes elements from a vector
*/

#include "vec.h"

#include <string.h>

void my_vec_remove(my_vec_t *vec, void *dst, size_t index)
{
    my_vec_remove_multiple(vec, dst, index, 1);
}

void my_vec_remove_multiple(
    my_vec_t *vec, void *dst, size_t index, size_t count)
{
    size_t length = vec->length;
    size_t to_shift_start = index + count;

    if (to_shift_start > length) {
        count = vec->length - index;
        to_shift_start = index + count;
    }
    memcpy(dst, my_vec_get(vec, index), vec->elem_size * count);
    vec->length -= count;
    if (to_shift_start == length)
        return;
    memmove(my_vec_get(vec, index), my_vec_get(vec, to_shift_start),
        (length - to_shift_start) * vec->elem_size);
}
