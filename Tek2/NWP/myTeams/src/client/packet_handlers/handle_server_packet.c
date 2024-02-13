/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Receive server packet
*/

#include "server_packet_handlers.h"

#include <stdio.h>

/// Checks if the packet is complete or too big,
/// if not, handles the packet normally.
static server_packet_result_t handle_packet_inner2(
    client_t *client, uint32_t id, uint32_t len, size_t max_cap)
{
    if (len > max_cap)
        return PRESULT_FULL_BUFFER;
    if (client->in_buf.len < len)
        return PRESULT_NOT_ENOUGH_DATA;
    return (*S2C_PACKET_HANDLERS[id])(client, len);
}

/// Reads the packet type and length, checks if the id exists,
/// then runs handle_packet_inner2().
static server_packet_result_t handle_packet_inner(client_t *client)
{
    size_t max_cap = client->in_buf.len;
    uint32_t id;
    uint32_t len;

    if (!my_cbuffer_pop_front_uleb128_32(&client->in_buf, &id)
        || !my_cbuffer_pop_front_uleb128_32(&client->in_buf, &len))
        return PRESULT_NOT_ENOUGH_DATA;
    if (id >= S2C_PACKET_COUNT || !S2C_PACKET_HANDLERS[id]) {
        puts("Unknown packet from server.");
        return PRESULT_OK;
    }
    max_cap = client->in_buf.cap - (max_cap - client->in_buf.len);
    return handle_packet_inner2(client, id, len, max_cap);
}

/// Drops all queued server packets.
static void drop_packets(client_t *client, server_packet_result_t reply)
{
    my_cbuffer_init(&client->in_buf, client->raw_in_buf, CLIENT_BUFFER_SIZE);
    my_cbuffer_init(
        &client->out_buf, client->raw_out_buf, CLIENT_BUFFER_SIZE);
    if (reply == PRESULT_FULL_BUFFER)
        puts("Too much data from server.");
    else
        puts("Internal client error.");
}

server_packet_result_t handle_packet_server(client_t *client)
{
    my_cbuffer_t prev_buf = client->in_buf;
    server_packet_result_t reply = handle_packet_inner(client);

    if (reply == PRESULT_OK)
        return PRESULT_OK;
    client->in_buf = prev_buf;
    if (reply == PRESULT_NOT_ENOUGH_DATA)
        return PRESULT_NOT_ENOUGH_DATA;
    drop_packets(client, reply);
    return reply;
}
