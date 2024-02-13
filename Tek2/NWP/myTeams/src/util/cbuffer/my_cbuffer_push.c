/*
** EPITECH PROJECT, 2022
** MyTeams - LibMy Excerpt
** File description:
** Pushes elements to a circular buffer
*/

#include "cbuffer.h"
#include "cbuffer/internal.h"
#include "leb128.h"

void my_cbuffer_push_front(my_cbuffer_t *buf, void const *src, size_t size)
{
    my_cbuffer_write_front(buf, src, size);
    buf->tail = my_cbuffer_wrap_sub(buf, buf->tail, size);
    buf->len += size;
}

void my_cbuffer_push_back(my_cbuffer_t *buf, void const *src, size_t size)
{
    my_cbuffer_write_back(buf, src, size);
    buf->head = my_cbuffer_wrap_add(buf, buf->head, size);
    buf->len += size;
}

size_t my_cbuffer_push_back_uleb128_32(my_cbuffer_t *buf, uint32_t value)
{
    uint8_t tmp[5];
    size_t size = uleb128_encode_32(tmp, value);

    if (size > buf->cap - buf->len)
        return 0;
    my_cbuffer_push_back(buf, tmp, size);
    return size;
}

size_t my_cbuffer_push_back_uleb128_64(my_cbuffer_t *buf, uint64_t value)
{
    uint16_t tmp[10];
    size_t size = uleb128_encode_64(tmp, value);

    if (size > buf->cap - buf->len)
        return 0;
    my_cbuffer_push_back(buf, tmp, size);
    return size;
}
