/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** C2S_GET_MESSAGES packet
*/

#include "peer.h"
#include "packet_handlers.h"
#include "packet_reply.h"

packet_result_t handle_get_messages_packet(peer_t *peer, size_t length)
{
    uuid_t recipient;

    if (!peer_check_logged_in(peer, length))
        return PRESULT_OK;
    if (length != sizeof(uuid_t)) {
        reply_error(peer, REPLY_INVALID_LENGTH,
            "get_messages requires a valid uuid", length);
        return PRESULT_OK;
    }
    my_cbuffer_pop_front(&peer->in_buf, &recipient, sizeof(uuid_t));
    reply_message_list(peer, recipient);
    return PRESULT_OK;
}
