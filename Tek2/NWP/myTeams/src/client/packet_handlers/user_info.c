/*
** EPITECH PROJECT, 2022
** Project
** File description:
** user_info
*/

#include "client.h"
#include "protocol.h"
#include "logging_client.h"
#include "server_packet_handlers.h"

#include <string.h>
#include <uuid/uuid.h>

server_packet_result_t s2c_handle_user_info_packet(
    client_t *client, uint32_t len)
{
    uuid_t id;
    uint64_t creation_date;
    uint32_t status = false;
    size_t length = client->in_buf.len;
    char name[MAX_NAME_LENGTH + 1] = {0};
    char id_str[37] = {0};

    my_cbuffer_pop_front(&client->in_buf, id, sizeof(uuid_t));
    my_cbuffer_pop_front_uleb128_64(&client->in_buf, &creation_date);
    my_cbuffer_pop_front_uleb128_32(&client->in_buf, &status);
    my_cbuffer_pop_front(
        &client->in_buf, name, len - (length - client->in_buf.len));
    uuid_unparse(id, id_str);
    client_print_user(id_str, name, status);
    return PRESULT_OK;
}
