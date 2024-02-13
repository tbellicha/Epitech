/*
** EPITECH PROJECT, 2022
** Project
** File description:
** handle_server_select
*/

#include "client.h"
#include "commands/commands.h"
#include "util.h"
#include "packet_handlers/server_packet_handlers.h"

#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

static bool handle_read_return_value(client_t *client, ssize_t rd)
{
    if (rd > 0) {
        my_cbuffer_push_back(&client->in_buf, client->tmp_buf, rd);
        return true;
    }
    if (rd < 0)
        printf("Error: %s.\n", strerror(errno));
    if (rd == 0)
        puts("Server closed the connection.");
    return false;
}

bool handle_server_select(client_t *client)
{
    ssize_t ret = 0;

    if (FD_ISSET(client->sock_fd, &client->fds_in)) {
        ret = read(client->sock_fd, client->tmp_buf,
            client->in_buf.cap - client->in_buf.len);
        if (handle_read_return_value(client, ret) == false)
            return false;
        handle_packet_server(client);
    }
    return true;
}
