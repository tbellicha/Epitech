/*
** EPITECH PROJECT, 2022
** Project
** File description:
** team_created
*/

#include "client.h"
#include "protocol.h"
#include "logging_client.h"
#include "server_packet_handlers.h"

#include <string.h>

server_packet_result_t s2c_handle_team_created_packet(
    client_t *client, uint32_t len)
{
    uint64_t creation_date;
    uuid_t creator_id;
    uuid_t team_id;
    uint32_t name_length;
    char name[MAX_NAME_LENGTH + 1] = {0};
    uint32_t desc_length = client->in_buf.len;
    char desc[MAX_DESCRIPTION_LENGTH + 1] = {0};
    char id_str[37] = {0};

    my_cbuffer_pop_front_uleb128_64(&client->in_buf, &creation_date);
    my_cbuffer_pop_front(&client->in_buf, creator_id, sizeof(uuid_t));
    my_cbuffer_pop_front(&client->in_buf, team_id, sizeof(uuid_t));
    my_cbuffer_pop_front_uleb128_32(&client->in_buf, &name_length);
    my_cbuffer_pop_front(&client->in_buf, name, name_length);
    desc_length -= len - client->in_buf.len;
    my_cbuffer_pop_front(&client->in_buf, desc, desc_length);
    uuid_unparse(team_id, id_str);
    client_event_team_created(id_str, name, desc);
    return PRESULT_OK;
}
