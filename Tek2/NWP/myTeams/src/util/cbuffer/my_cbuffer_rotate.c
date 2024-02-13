/*
** EPITECH PROJECT, 2022
** MyTeams - LibMy Excerpt
** File description:
** Rotates a circular buffer
*/

#include "cbuffer.h"
#include "cbuffer/internal.h"

void my_cbuffer_rotate_left(my_cbuffer_t *buf, size_t amt)
{
    char *data = buf->data;

    amt %= buf->len == 0 ? 1 : buf->len;
    if (amt == 0)
        return;
    if (buf->head == buf->tail) {
        buf->head = my_cbuffer_wrap_add(buf, buf->head, amt);
        buf->tail = buf->head;
        return;
    }
    while (amt > 0) {
        data[buf->head] = data[buf->tail];
        buf->head = my_cbuffer_wrap_add(buf, buf->head, 1);
        buf->tail = my_cbuffer_wrap_add(buf, buf->tail, 1);
        --amt;
    }
}

void my_cbuffer_rotate_right(my_cbuffer_t *buf, size_t amt)
{
    char *data = buf->data;

    amt %= buf->len == 0 ? 1 : buf->len;
    if (amt == 0)
        return;
    if (buf->head == buf->tail) {
        buf->head = my_cbuffer_wrap_sub(buf, buf->head, amt);
        buf->tail = buf->head;
        return;
    }
    while (amt > 0) {
        buf->head = my_cbuffer_wrap_sub(buf, buf->head, 1);
        buf->tail = my_cbuffer_wrap_sub(buf, buf->tail, 1);
        data[buf->tail] = data[buf->head];
        --amt;
    }
}
