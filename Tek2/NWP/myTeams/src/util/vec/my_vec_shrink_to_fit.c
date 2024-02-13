/*
** EPITECH PROJECT, 2022
** MyTeams - LibMy Excerpt
** File description:
** Shrinks the capacity of the vec as much as possible
*/

#include "vec.h"

my_vec_err_t my_vec_shrink_to_fit(my_vec_t *vec)
{
    return my_vec_set_capacity(vec, vec->length, NULL);
}
