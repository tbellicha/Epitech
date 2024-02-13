/*
** EPITECH PROJECT, 2022
** Project
** File description:
** message_created
*/

#include "client.h"
#include "protocol.h"
#include "logging_client.h"
#include "server_packet_handlers.h"

server_packet_result_t s2c_handle_message_created_packet(
    client_t *client, uint32_t len)
{
    size_t length_date;
    uint64_t creation_date;
    uuid_t creator_id;
    uuid_t recipient_id;
    char body[MAX_BODY_LENGTH + 1] = {0};
    char id_str[37] = {0};

    length_date = client->in_buf.len;
    my_cbuffer_pop_front_uleb128_64(&client->in_buf, &creation_date);
    length_date -= client->in_buf.len;
    my_cbuffer_pop_front(&client->in_buf, creator_id, sizeof(uuid_t));
    my_cbuffer_pop_front(&client->in_buf, recipient_id, sizeof(uuid_t));
    my_cbuffer_pop_front(
        &client->in_buf, body, len - (length_date + sizeof(uuid_t) * 2));
    uuid_unparse(creator_id, id_str);
    if (uuid_compare(recipient_id, client->uuid) == 0)
        client_event_private_message_received(id_str, body);
    return PRESULT_OK;
}
