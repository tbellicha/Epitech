/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** generic error packet
*/

#include "peer.h"
#include "protocol.h"
#include "packet_reply.h"

void reply_error(peer_t *peer, reply_code_t code, char const *description,
    size_t bytes_to_drop)
{
    my_cbuffer_pop_front(&peer->in_buf, NULL, bytes_to_drop);
    reply_generic(peer, code, description);
}
