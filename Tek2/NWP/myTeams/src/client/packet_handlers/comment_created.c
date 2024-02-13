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

#include <string.h>

static void call_event_comment_created(uuid_t thread_id, uuid_t user_id,
    uint64_t reply_timestamp, char const *reply_body)
{
    char thread_id_str[37] = {0};
    char user_id_str[37] = {0};

    uuid_unparse(thread_id, thread_id_str);
    uuid_unparse(user_id, user_id_str);
    client_print_reply_created(
        thread_id_str, user_id_str, reply_timestamp, reply_body);
}

static void call_event_reply_received(
    uuid_t team_id, uuid_t thread_id, uuid_t user_id, char const *reply_body)
{
    char team_id_str[37] = {0};
    char thread_id_str[37] = {0};
    char user_id_str[37] = {0};

    uuid_unparse(team_id, team_id_str);
    uuid_unparse(thread_id, thread_id_str);
    uuid_unparse(user_id, user_id_str);
    client_event_thread_reply_received(
        team_id_str, thread_id_str, user_id_str, reply_body);
}

static void fill_struct(
    reply_created_path_t *h_st, client_t *client, size_t length)
{
    h_st->length_before_body = length;
    memset(h_st->body, 0, MAX_BODY_LENGTH + 1);

    my_cbuffer_pop_front_uleb128_64(&client->in_buf, &h_st->creation_date);
    my_cbuffer_pop_front(&client->in_buf, h_st->creator_id, sizeof(uuid_t));
    my_cbuffer_pop_front(&client->in_buf, h_st->team_id, sizeof(uuid_t));
    my_cbuffer_pop_front(&client->in_buf, h_st->channel_id, sizeof(uuid_t));
    my_cbuffer_pop_front(&client->in_buf, h_st->thread_id, sizeof(uuid_t));
    my_cbuffer_pop_front(&client->in_buf, h_st->comment_id, sizeof(uuid_t));
    my_cbuffer_pop_front(&client->in_buf, h_st->body,
        h_st->length_before_body - (length - client->in_buf.len));
}

server_packet_result_t s2c_handle_comment_created_packet(
    client_t *client, uint32_t len)
{
    reply_created_path_t help_struct;

    fill_struct(&help_struct, client, len);
    if (uuid_compare(client->uuid, help_struct.creator_id)) {
        call_event_reply_received(help_struct.team_id, help_struct.thread_id,
            help_struct.creator_id, help_struct.body);
    } else {
        call_event_comment_created(help_struct.thread_id,
            help_struct.creator_id, help_struct.creation_date,
            help_struct.body);
    }
    return PRESULT_OK;
}
