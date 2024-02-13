/*
** EPITECH PROJECT, 2022
** Project
** File description:
** send
*/

#include "client.h"
#include "commands.h"
#include "protocol.h"
#include "error_messages.h"

#include <unistd.h>
#include <uuid/uuid.h>

void command_send(client_t *client, char *params)
{
    ssize_t len_uuid = check_uuid(params, UUID_USER_ERROR_MESSAGE);
    int start_message = len_uuid + 3;
    ssize_t len_message =
        parse_string(&params[start_message], "Parse string failed");
    uuid_t uuid;

    if (len_uuid <= 0 || len_message <= 0 || len_message > MAX_BODY_LENGTH) {
        puts("Invalid or too long parameters");
        return;
    }
    uuid_parse(&params[1], uuid);
    my_cbuffer_push_back_uleb128_32(&client->out_buf, C2S_SEND_MESSAGE);
    my_cbuffer_push_back_uleb128_32(&client->out_buf, 16 + len_message);
    my_cbuffer_push_back(&client->out_buf, uuid, sizeof(uuid_t));
    my_cbuffer_push_back(
        &client->out_buf, &params[start_message + 1], len_message);
}

void print_helper_send(void)
{
    puts("/send \"user_uuid\" \"message_body\": Send a message to a user");
}
