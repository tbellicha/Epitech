/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Get users list packet
*/

#include "peer.h"
#include "packet_handlers.h"
#include "packet_reply.h"

packet_result_t handle_get_users_packet(peer_t *peer, size_t length)
{
    if (!peer_check_logged_in(peer, length))
        return PRESULT_OK;
    if (length != 0) {
        reply_error(peer, REPLY_INVALID_LENGTH,
            "user list packet should be empty", length);
        return PRESULT_OK;
    }
    reply_user_list(peer);
    return PRESULT_OK;
}
