/*
** EPITECH PROJECT, 2022
** MyTeams - LibMy Excerpt
** File description:
** Ensures the vector has a capacity of at least min_cap
*/

#include "vec.h"

my_vec_err_t my_vec_ensure_capacity(my_vec_t *vec, size_t min_cap)
{
    if (min_cap <= vec->capacity)
        return MY_VEC_OK;
    return my_vec_reserve(vec, min_cap - vec->length);
}
