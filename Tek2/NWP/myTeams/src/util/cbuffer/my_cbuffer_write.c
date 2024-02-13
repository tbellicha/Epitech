/*
** EPITECH PROJECT, 2022
** MyTeams - LibMy Excerpt
** File description:
** Writes to a circular buffer
*/

#include <string.h>

#include "cbuffer.h"

// Writes the given bytes *before* buf->tail.
//
// Examples for size = 2:
// # = filled, . = empty, T = tail (filled), H = head
//
// CASE 1: T = 7, H = 3: [###H...T##] -> [###H.T####]
// CASE 2: T = 1, H = 5: [.T###H....] -> [#####H...T]
// CASE 3: T = 2, H = 8: [..T#####H.] -> [T#######H.]
void my_cbuffer_write_front(my_cbuffer_t *buf, void const *src, size_t size)
{
    if (buf->tail > buf->head) {
        memcpy((char *)buf->data + (buf->tail - size), src, size);
    } else if (buf->tail < size) {
        size_t first_part = buf->tail;
        size_t second_part = size - first_part;

        memcpy(buf->data, (char *)src + second_part, first_part);
        memcpy(
            (char *)buf->data + (buf->cap - second_part), src, second_part);
    } else {
        memcpy((char *)buf->data + (buf->tail - size), src, size);
    }
}

// Writes the given bytes *after* buf->head (inclusive).
//
// Examples for size = 2:
// # = filled, . = empty, T = tail (filled), H = head
//
// CASE 1: T = 7, H = 3: [###H...T##] -> [#####H.T##]
// CASE 2: T = 5, H = 9: [.....T###H] -> [#H...T####]
// CASE 3: T = 2, H = 8: [..T#####H.] -> [H.T#######]
void my_cbuffer_write_back(my_cbuffer_t *buf, void const *src, size_t size)
{
    if (buf->tail <= buf->head && buf->head > buf->cap - size) {
        size_t first_part = buf->cap - buf->head;
        size_t second_part = size - first_part;

        memcpy((char *)buf->data + buf->head, src, first_part);
        memcpy(buf->data, (char *)src + first_part, second_part);
    } else {
        memcpy((char *)buf->data + buf->head, src, size);
    }
}
