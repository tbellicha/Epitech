/*
** EPITECH PROJECT, 2022
** Project
** File description:
** channel_created
*/

#include "client.h"
#include "protocol.h"
#include "logging_client.h"
#include "server_packet_handlers.h"

static void call_event_channel_created(
    uuid_t channel_id, char *name, char *desc)
{
    char id_str[37] = {0};

    uuid_unparse(channel_id, id_str);
    client_event_channel_created(id_str, name, desc);
}

server_packet_result_t s2c_handle_channel_created_packet(
    client_t *client, uint32_t len)
{
    uint64_t creation_date;
    uuid_t creator_id;
    uuid_t team_id;
    uuid_t channel_id;
    uint32_t name_length;
    char name[MAX_NAME_LENGTH + 1] = {0};
    uint32_t length_before_desc = client->in_buf.len;
    char desc[MAX_DESCRIPTION_LENGTH + 1] = {0};

    my_cbuffer_pop_front_uleb128_64(&client->in_buf, &creation_date);
    my_cbuffer_pop_front(&client->in_buf, creator_id, sizeof(uuid_t));
    my_cbuffer_pop_front(&client->in_buf, team_id, sizeof(uuid_t));
    my_cbuffer_pop_front(&client->in_buf, channel_id, sizeof(uuid_t));
    my_cbuffer_pop_front_uleb128_32(&client->in_buf, &name_length);
    my_cbuffer_pop_front(&client->in_buf, name, name_length);
    my_cbuffer_pop_front(&client->in_buf, desc,
        length_before_desc - (len - client->in_buf.len));
    call_event_channel_created(channel_id, name, desc);
    return PRESULT_OK;
}
