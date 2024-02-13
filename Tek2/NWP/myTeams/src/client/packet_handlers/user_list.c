/*
** EPITECH PROJECT, 2022
** Project
** File description:
** user_list
*/

#include "client.h"
#include "protocol.h"
#include "logging_client.h"
#include "server_packet_handlers.h"

#include <string.h>

server_packet_result_t s2c_handle_user_list_packet(
    client_t *client, uint32_t len)
{
    uint32_t count;
    uuid_t id;
    char name[MAX_NAME_LENGTH + 1] = {0};
    uint32_t name_length;
    char id_str[37] = {0};
    uint32_t status = false;

    (void)len;
    my_cbuffer_pop_front_uleb128_32(&client->in_buf, &count);
    for (size_t i = 0; i < count; i++) {
        memset(name, 0, sizeof(name));
        memset(id_str, 0, sizeof(id_str));
        my_cbuffer_pop_front(&client->in_buf, id, sizeof(uuid_t));
        my_cbuffer_pop_front_uleb128_32(&client->in_buf, &name_length);
        my_cbuffer_pop_front(&client->in_buf, name, name_length);
        my_cbuffer_pop_front_uleb128_32(&client->in_buf, &status);
        uuid_unparse(id, id_str);
        client_print_users(id_str, name, status);
    }
    return PRESULT_OK;
}
