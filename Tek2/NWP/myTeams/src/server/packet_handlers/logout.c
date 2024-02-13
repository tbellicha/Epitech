/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Receive logout client packet
*/

#include "peer.h"
#include "server.h"
#include "packet_handlers.h"
#include "packet_reply.h"

#include <string.h>
#include <uuid/uuid.h>

packet_result_t handle_logout_packet(peer_t *peer, size_t length)
{
    if (!peer_check_logged_in(peer, length))
        return PRESULT_OK;
    if (length != 0) {
        reply_error(peer, REPLY_INVALID_LENGTH,
            "logout packet should be empty", length);
        return PRESULT_OK;
    }
    peer_unset_user(peer, true);
    return PRESULT_OK;
}
