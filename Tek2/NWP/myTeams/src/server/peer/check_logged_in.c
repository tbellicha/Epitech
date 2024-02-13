/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Check that a peer is logged in
*/

#include "peer.h"
#include "packet_reply.h"

#include <uuid/uuid.h>

bool peer_check_logged_in(peer_t *peer, size_t packet_length)
{
    if (peer->user)
        return true;
    reply_error(peer, REPLY_NOT_LOGGED_IN, "not logged in", packet_length);
    return false;
}
