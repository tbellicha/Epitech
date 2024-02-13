/*
** EPITECH PROJECT, 2022
** MyTeams - LibMy Excerpt
** File description:
** Reads from a circular buffer to a file
*/

#include "cbuffer.h"
#include "cbuffer/internal.h"

#include <unistd.h>

ssize_t my_cbuffer_read_front_to(my_cbuffer_t const *buf, int fd)
{
    void *ptrs[2];
    size_t sizes[2];
    ssize_t ret;
    ssize_t ret2;

    my_cbuffer_get_parts(buf, ptrs, sizes);
    ret = write(fd, ptrs[0], sizes[0]);
    if (ret <= 0 || (size_t)ret < sizes[0] || sizes[1] == 0)
        return ret;
    ret2 = write(fd, ptrs[1], sizes[1]);
    if (ret2 < 0)
        return ret2;
    return ret + ret2;
}
