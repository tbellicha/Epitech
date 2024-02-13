/*
** EPITECH PROJECT, 2022
** MyTeams - LibMy Excerpt
** File description:
** Reads from a circular buffer to a file
*/

#include "cbuffer.h"
#include "cbuffer/internal.h"

#include <unistd.h>

ssize_t my_cbuffer_pop_front_to(my_cbuffer_t *buf, int fd)
{
    ssize_t ret = my_cbuffer_read_front_to(buf, fd);

    if (ret <= 0)
        return ret;
    my_cbuffer_pop_front(buf, NULL, (size_t)ret);
    return ret;
}
