/*
** EPITECH PROJECT, 2022
** Project
** File description:
** subscribed
*/

#include "client.h"
#include "protocol.h"
#include "error_messages.h"

#include <stdio.h>
#include <unistd.h>
#include <uuid/uuid.h>

void command_subscribed(client_t *client, char *params)
{
    ssize_t length = 0;
    uuid_t uuid;

    if (!params[0]) {
        write_u32(client->sock_fd, C2S_GET_SUBSCRIBED_TEAMS);
        write_u32(client->sock_fd, 0);
        return;
    }
    length = check_uuid(params, UUID_TEAM_ERROR_MESSAGE);
    if (length <= 0)
        return;
    uuid_parse(&params[1], uuid);
    my_cbuffer_push_back_uleb128_32(&client->out_buf, C2S_GET_TEAM_USERS);
    my_cbuffer_push_back_uleb128_32(&client->out_buf, 16);
    my_cbuffer_push_back(&client->out_buf, uuid, 16);
}

/// Print helper of the subscribed command.
void print_helper_subscribed(void)
{
    fputs("/subscribed ?\"team_uuid\": List all subscribed teams", stdout);
    fputs(" or list all users subscribed to a team\n", stdout);
}
