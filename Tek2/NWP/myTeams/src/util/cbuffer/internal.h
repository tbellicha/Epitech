/*
** EPITECH PROJECT, 2022
** MyTeams - LibMy Excerpt
** File description:
** The internals for the memory module
*/

#pragma once

#include "cbuffer.h"

static inline size_t my_cbuffer_wrap_add(
    my_cbuffer_t const *buf, size_t index, size_t to_add)
{
    if (index >= buf->cap - to_add)
        return to_add - (buf->cap - index);
    else
        return index + to_add;
}

static inline size_t my_cbuffer_wrap_sub(
    my_cbuffer_t const *buf, size_t index, size_t to_sub)
{
    if (to_sub > index)
        return buf->cap + index - to_sub;
    else
        return index - to_sub;
}
