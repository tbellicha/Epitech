/*
** EPITECH PROJECT, 2022
** Project
** File description:
** logout
*/

#include "client.h"
#include "protocol.h"
#include "logging_client.h"
#include "server_packet_handlers.h"

#include <stdio.h>
#include <string.h>
#include <uuid/uuid.h>

server_packet_result_t s2c_handle_message_list_packet(
    client_t *client, uint32_t len)
{
    uint32_t count;
    uuid_t id;
    uint64_t timestamp;
    char body[MAX_BODY_LENGTH + 1] = {0};
    uint32_t body_length;
    char id_str[37] = {0};

    (void)len;
    my_cbuffer_pop_front_uleb128_32(&client->in_buf, &count);
    for (size_t i = 0; i < count; i++) {
        memset(body, 0, sizeof(body));
        memset(id_str, 0, sizeof(id_str));
        my_cbuffer_pop_front(&client->in_buf, id, sizeof(uuid_t));
        my_cbuffer_pop_front_uleb128_64(&client->in_buf, &timestamp);
        my_cbuffer_pop_front_uleb128_32(&client->in_buf, &body_length);
        my_cbuffer_pop_front(&client->in_buf, body, body_length);
        uuid_unparse(id, id_str);
        client_private_message_print_messages(id_str, timestamp, body);
    }
    return PRESULT_OK;
}
