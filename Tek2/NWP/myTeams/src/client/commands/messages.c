/*
** EPITECH PROJECT, 2022
** Project
** File description:
** messages
*/

#include "client.h"
#include "protocol.h"
#include "error_messages.h"

#include <stdio.h>
#include <unistd.h>
#include <uuid/uuid.h>

void command_messages(client_t *client, char *params)
{
    ssize_t length = 0;
    uuid_t uuid;

    if (!params[0]) {
        puts(UUID_USER_ERROR_MESSAGE);
        return;
    }
    length = check_uuid(params, UUID_USER_ERROR_MESSAGE);
    if (length <= 0)
        return;
    uuid_parse(&params[1], uuid);
    my_cbuffer_push_back_uleb128_32(&client->out_buf, C2S_GET_MESSAGES);
    my_cbuffer_push_back_uleb128_32(&client->out_buf, 16);
    my_cbuffer_push_back(&client->out_buf, uuid, 16);
}

void print_helper_messages(void)
{
    puts("/messages \"user_uuid\": List all messages exchange with an user");
}
