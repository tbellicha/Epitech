/*
** EPITECH PROJECT, 2022
** Project
** File description:
** unknown_item
*/

#include "logging_client.h"
#include "server_packet_handlers.h"

static void print_unknown_item(const char *item_id, reply_code_t item_type)
{
    switch (item_type) {
        case REPLY_UNKNOWN_TEAM: client_error_unknown_team(item_id); break;
        case REPLY_UNKNOWN_CHANNEL:
            client_error_unknown_channel(item_id);
            break;
        case REPLY_UNKNOWN_THREAD:
            client_error_unknown_thread(item_id);
            break;
        case REPLY_UNKNOWN_USER: client_error_unknown_user(item_id); break;
        default: break;
    }
}

server_packet_result_t s2c_handle_unknown_item_packet(
    client_t *client, uint32_t len)
{
    uuid_t item_id;
    reply_code_t item_type;
    char item_id_str[37] = {0};

    (void)len;
    my_cbuffer_pop_front_uleb128_32(&client->in_buf, &item_type);
    my_cbuffer_pop_front(&client->in_buf, item_id, sizeof(uuid_t));
    uuid_unparse(item_id, item_id_str);
    print_unknown_item(item_id_str, item_type);
    return PRESULT_OK;
}
