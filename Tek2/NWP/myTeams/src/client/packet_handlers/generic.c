/*
** EPITECH PROJECT, 2022
** Project
** File description:
** generic
*/

#include "client.h"
#include "protocol.h"
#include "logging_client.h"
#include "server_packet_handlers.h"

#include <stdio.h>

static void handle_reply_code(uint32_t reply_code)
{
    switch (reply_code) {
        case REPLY_NOT_LOGGED_IN: client_error_unauthorized(); break;
        case REPLY_ALREADY_EXISTS: client_error_already_exist(); break;
        default: break;
    }
}

server_packet_result_t s2c_handle_generic_packet(
    client_t *client, uint32_t len)
{
    uint32_t reply_code;
    size_t reply_code_length = client->in_buf.len;
    char body[MAX_BODY_LENGTH + 1] = {0};

    my_cbuffer_pop_front_uleb128_32(&client->in_buf, &reply_code);
    reply_code_length -= client->in_buf.len;
    my_cbuffer_pop_front(&client->in_buf, body, len - reply_code_length);
    printf("%u: %s\n", reply_code, body);
    handle_reply_code(reply_code);
    return PRESULT_OK;
}
