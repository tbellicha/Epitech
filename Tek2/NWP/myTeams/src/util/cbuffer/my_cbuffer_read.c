/*
** EPITECH PROJECT, 2022
** MyTeams - LibMy Excerpt
** File description:
** Reads from a circular buffer
*/

#include "cbuffer.h"
#include "cbuffer/internal.h"
#include "util.h"

#include <string.h>

void *my_cbuffer_read_front(my_cbuffer_t const *buf, void *dst, size_t size)
{
    size_t first_len;
    void *first = my_cbuffer_get_first_part(buf, &first_len);
    size_t to_read = MY_MIN(first_len, size);
    size_t remaining = size - to_read;

    memcpy(dst, first, to_read);
    if (remaining > 0)
        memcpy((char *)dst + to_read, my_cbuffer_get_second_part(buf, NULL),
            remaining);
    return dst;
}

void *my_cbuffer_read_back(my_cbuffer_t const *buf, void *dst, size_t size)
{
    size_t sizes[2];
    char *parts[2];
    size_t to_read;
    size_t remaining;

    my_cbuffer_get_parts(buf, (void **)parts, sizes);
    if (!my_cbuffer_is_contiguous(buf)) {
        to_read = MY_MIN(sizes[1], size);
        remaining = size - to_read;
        memcpy((char *)dst + remaining, parts[1] + (sizes[1] - to_read),
            to_read);
        if (remaining > 0)
            memcpy(dst, parts[0] + (sizes[0] - remaining), remaining);
    } else {
        to_read = MY_MIN(sizes[0], size);
        memcpy(dst, parts[0] + (sizes[0] - to_read), to_read);
    }
    return dst;
}

void *my_cbuffer_read_at(
    my_cbuffer_t const *buf, void *dst, size_t size, size_t offset)
{
    my_cbuffer_t tmp = *buf;

    tmp.tail = my_cbuffer_wrap_add(&tmp, tmp.tail, offset);
    return my_cbuffer_read_front(&tmp, dst, size);
}
