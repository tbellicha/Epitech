/*
** EPITECH PROJECT, 2022
** MyTeams - LibMy Excerpt
** File description:
** Initializes a circular buffer
*/

#include "cbuffer.h"

void my_cbuffer_init(my_cbuffer_t *buf, void *data, size_t capacity)
{
    buf->data = data;
    buf->cap = capacity;
    buf->len = 0;
    buf->head = 0;
    buf->tail = 0;
}
