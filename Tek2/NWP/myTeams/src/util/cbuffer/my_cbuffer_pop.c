/*
** EPITECH PROJECT, 2022
** MyTeams - LibMy Excerpt
** File description:
** Pop operations for circular buffers
*/

#include "cbuffer.h"
#include "cbuffer/internal.h"
#include "leb128.h"
#include "util.h"

void *my_cbuffer_pop_front(my_cbuffer_t *buf, void *dst, size_t size)
{
    size = MY_MIN(size, buf->len);
    if (dst)
        my_cbuffer_read_front(buf, dst, size);
    buf->tail = my_cbuffer_wrap_add(buf, buf->tail, size);
    buf->len -= size;
    return dst;
}

bool my_cbuffer_pop_front_uleb128_32(
    my_cbuffer_t *restrict buf, uint32_t *restrict output)
{
    uint8_t tmp[5];
    size_t size;

    my_cbuffer_read_front(buf, tmp, 5);
    size = uleb128_decode_32(tmp, output);
    if (size > buf->len)
        return false;
    my_cbuffer_pop_front(buf, NULL, size);
    return true;
}

bool my_cbuffer_pop_front_uleb128_64(
    my_cbuffer_t *restrict buf, uint64_t *restrict output)
{
    uint8_t tmp[10];
    size_t size;

    my_cbuffer_read_front(buf, tmp, 10);
    size = uleb128_decode_64(tmp, output);
    if (size > buf->len)
        return false;
    my_cbuffer_pop_front(buf, NULL, size);
    return true;
}

void *my_cbuffer_pop_back(my_cbuffer_t *buf, void *dst, size_t size)
{
    size = MY_MIN(size, buf->len);
    if (dst)
        my_cbuffer_read_back(buf, dst, size);
    buf->head = my_cbuffer_wrap_sub(buf, buf->head, size);
    buf->len -= size;
    return dst;
}
