/*
** EPITECH PROJECT, 2022
** Project
** File description:
** packet_header
*/

#include "leb128.h"

#include <unistd.h>

ssize_t write_u32(int sock_fd, uint32_t data)
{
    char buff[5];

    return write(sock_fd, buff, uleb128_encode_32(buff, data));
}
