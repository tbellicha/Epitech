/*
** EPITECH PROJECT, 2022
** Project
** File description:
** send_packet
*/

#include "client.h"

#include <errno.h>
#include <stdio.h>
#include <string.h>

void send_packet(client_t *client)
{
    ssize_t ret = my_cbuffer_pop_front_to(&client->out_buf, client->sock_fd);

    if (ret > 0)
        return;
    if (ret < 0)
        printf("Connection closed (%s)\n", strerror(errno));
    else
        puts("Connection closed (output closed)");
}
