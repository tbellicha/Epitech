/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Receive login client packet
*/

#include "peer.h"
#include "server.h"
#include "packet_handlers.h"
#include "packet_reply.h"

#include <stdbool.h>
#include <string.h>

/// Checks if the packet is complete or too big,
/// if not, handles the packet normally.
static packet_result_t handle_packet_inner2(
    peer_t *peer, uint32_t id, uint32_t len, size_t max_cap)
{
    if (len > max_cap)
        return PRESULT_FULL_BUFFER;
    if (peer->in_buf.len < len)
        return PRESULT_NOT_ENOUGH_DATA;
    return (*PACKET_HANDLERS[id])(peer, len);
}

/// Reads the packet type and length, checks if the id exists,
/// then runs handle_packet_inner2().
static packet_result_t handle_packet_inner(peer_t *peer)
{
    size_t max_cap = peer->in_buf.len;
    uint32_t id;
    uint32_t len;

    if (!my_cbuffer_pop_front_uleb128_32(&peer->in_buf, &id)
        || !my_cbuffer_pop_front_uleb128_32(&peer->in_buf, &len))
        return PRESULT_NOT_ENOUGH_DATA;
    if (id >= C2S_PACKET_COUNT || !PACKET_HANDLERS[id])
        return handle_unknown_packet(peer, len);
    max_cap = peer->in_buf.cap - (max_cap - peer->in_buf.len);
    return handle_packet_inner2(peer, id, len, max_cap);
}

/// Drops all queued peer packets.
static void drop_packets(peer_t *peer, packet_result_t reply)
{
    my_cbuffer_init(&peer->in_buf, peer->raw_in_buf, PEER_BUFFER_SIZE);
    my_cbuffer_init(&peer->out_buf, peer->raw_out_buf, PEER_BUFFER_SIZE);
    if (reply == PRESULT_FULL_BUFFER)
        reply_generic(peer, REPLY_TRUNCATION, "too much data sent");
    else
        reply_generic(peer, REPLY_INTERNAL_ERROR, "internal server error");
}

packet_result_t handle_packet(peer_t *peer)
{
    my_cbuffer_t prev_buf = peer->in_buf;
    packet_result_t reply = handle_packet_inner(peer);

    if (reply == PRESULT_OK)
        return PRESULT_OK;
    peer->in_buf = prev_buf;
    if (reply == PRESULT_NOT_ENOUGH_DATA)
        return PRESULT_NOT_ENOUGH_DATA;
    drop_packets(peer, reply);
    return reply;
}
