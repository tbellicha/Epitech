/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Get users list packet
*/

#include "peer.h"
#include "packet_handlers.h"
#include "packet_reply.h"

packet_result_t handle_get_team_info_packet(peer_t *peer, size_t length)
{
    uuid_t team_uuid;

    if (!peer_check_logged_in(peer, length))
        return PRESULT_OK;
    if (length != sizeof(uuid_t)) {
        reply_error(peer, REPLY_INVALID_LENGTH,
            "team info list packet should contain a uuid", length);
        return PRESULT_OK;
    }
    my_cbuffer_pop_front(&peer->in_buf, &team_uuid, sizeof(uuid_t));
    reply_team_info(peer, team_uuid, length);
    return PRESULT_OK;
}
