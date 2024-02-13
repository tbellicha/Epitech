/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** create_item
*/

#include "peer.h"
#include "server.h"
#include "packet_handlers.h"
#include "packet_reply.h"

#include <stdlib.h>

static bool decode_create_item_packet(
    create_item_packet_t *packet, peer_t *peer, size_t length)
{
    size_t name_length_size;

    if (sizeof(uuid_t) > length)
        return false;
    my_cbuffer_pop_front(&peer->in_buf, &packet->context_id, sizeof(uuid_t));
    length -= sizeof(uuid_t);
    name_length_size = peer->in_buf.len;
    my_cbuffer_pop_front_uleb128_32(&peer->in_buf, &packet->name_length);
    name_length_size -= peer->in_buf.len;
    if (name_length_size == 0 || name_length_size > length
        || name_length_size > MAX_NAME_LENGTH)
        return false;
    length -= name_length_size + packet->name_length;
    my_cbuffer_pop_front(&peer->in_buf, &packet->name, packet->name_length);
    packet->body_length = length;
    if (packet->body_length > MAX_ITEM_BODY_LENGTH)
        return false;
    my_cbuffer_pop_front(&peer->in_buf, &packet->body, packet->body_length);
    return true;
}

static packet_result_t execute_create_item_packet(
    create_item_packet_t *packet, peer_t *peer)
{
    context_type_t type =
        server_get_context_type(peer->server, packet->context_id);
    peer_item_creator_t create_item = PEER_ITEM_CREATORS[type];

    if (peer_item_exists_by_name(peer, packet->name)) {
        reply_error(peer, REPLY_ALREADY_EXISTS, "already exists", 0);
        return PRESULT_OK;
    }
    if (!(*create_item)(peer, packet->context_id, packet->name, packet->body))
        return PRESULT_INTERNAL_ERROR;
    return PRESULT_OK;
}

packet_result_t handle_create_item_packet(peer_t *peer, size_t length)
{
    create_item_packet_t *packet;
    packet_result_t result;

    if (!peer_check_logged_in(peer, length))
        return PRESULT_OK;
    packet = calloc(sizeof(*packet), 1);
    if (!packet)
        return PRESULT_INTERNAL_ERROR;
    if (!decode_create_item_packet(packet, peer, length)) {
        reply_error(peer, REPLY_INVALID_LENGTH,
            "too long or truncated packet data", length);
        free(packet);
        return PRESULT_OK;
    }
    result = execute_create_item_packet(packet, peer);
    free(packet);
    return result;
}
