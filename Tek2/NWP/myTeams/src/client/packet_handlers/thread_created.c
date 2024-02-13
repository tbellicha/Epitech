/*
** EPITECH PROJECT, 2022
** Project
** File description:
** thread_created
*/

#include "client.h"
#include "protocol.h"
#include "logging_client.h"
#include "server_packet_handlers.h"

static void read_items_id(
    client_t *client, uuid_t team_id, uuid_t channel_id, uuid_t thread_id)
{
    my_cbuffer_pop_front(&client->in_buf, team_id, sizeof(uuid_t));
    my_cbuffer_pop_front(&client->in_buf, channel_id, sizeof(uuid_t));
    my_cbuffer_pop_front(&client->in_buf, thread_id, sizeof(uuid_t));
}

server_packet_result_t s2c_handle_thread_created_packet(
    client_t *client, uint32_t len)
{
    uint64_t creation_date;
    id_path_t ids;
    uint32_t title_length;
    char title[MAX_NAME_LENGTH + 1] = {0};
    char body[MAX_BODY_LENGTH + 1] = {0};
    uint32_t len_before_body = client->in_buf.len;

    my_cbuffer_pop_front_uleb128_64(&client->in_buf, &creation_date);
    my_cbuffer_pop_front(&client->in_buf, ids.creator, sizeof(uuid_t));
    read_items_id(client, ids.team, ids.channel, ids.thread);
    my_cbuffer_pop_front_uleb128_32(&client->in_buf, &title_length);
    my_cbuffer_pop_front(&client->in_buf, title, title_length);
    my_cbuffer_pop_front(
        &client->in_buf, body, len_before_body - (len - client->in_buf.len));
    uuid_unparse(ids.creator, ids.creator_str);
    uuid_unparse(ids.thread, ids.thread_str);
    client_event_thread_created(
        ids.thread_str, ids.creator_str, creation_date, title, body);
    return PRESULT_OK;
}
