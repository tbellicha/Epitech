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

void pop_first_part(
    client_t *client, uuid_t *id, uint64_t *creation_date, uuid_t *author_id)
{
    my_cbuffer_pop_front(&client->in_buf, *id, sizeof(uuid_t));
    my_cbuffer_pop_front_uleb128_64(&client->in_buf, creation_date);
    my_cbuffer_pop_front(&client->in_buf, *author_id, sizeof(uuid_t));
}

server_packet_result_t s2c_handle_team_info_packet(
    client_t *client, uint32_t len)
{
    uint32_t name_length;
    uuid_t id;
    uuid_t author_id;
    uint64_t creation_date;
    size_t length = client->in_buf.len;
    char name[MAX_NAME_LENGTH + 1] = {0};
    char desc[MAX_NAME_LENGTH + 1] = {0};
    char id_str[37] = {0};
    char author_id_str[37] = {0};

    pop_first_part(client, &id, &creation_date, &author_id);
    my_cbuffer_pop_front_uleb128_32(&client->in_buf, &name_length);
    my_cbuffer_pop_front(&client->in_buf, name, name_length);
    my_cbuffer_pop_front(
        &client->in_buf, desc, len - (length - client->in_buf.len));
    uuid_unparse(id, id_str);
    uuid_unparse(author_id, author_id_str);
    client_print_team(id_str, name, desc);
    return PRESULT_OK;
}
