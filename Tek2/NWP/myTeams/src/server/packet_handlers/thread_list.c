/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Get thread list packet
*/

#include "peer.h"
#include "packet_handlers.h"
#include "packet_reply.h"

#include <uuid/uuid.h>

packet_result_t handle_get_threads_packet(peer_t *peer, size_t length)
{
    uuid_t team_id;
    uuid_t channel_id;

    if (!peer_check_logged_in(peer, length))
        return PRESULT_OK;
    if (length != 2 * sizeof(uuid_t)) {
        reply_error(peer, REPLY_INVALID_LENGTH,
            "channel list packet should contain two uuids", length);
        return PRESULT_OK;
    }
    my_cbuffer_pop_front(&peer->in_buf, &team_id, sizeof(uuid_t));
    my_cbuffer_pop_front(&peer->in_buf, &channel_id, sizeof(uuid_t));
    reply_thread_list(peer, team_id, channel_id);
    return PRESULT_OK;
}
