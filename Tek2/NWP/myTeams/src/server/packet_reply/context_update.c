/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** context_update
*/

#include "peer.h"

void reply_context_update(peer_t *peer)
{
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, S2C_CONTEXT_UPDATE);
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, 1 + sizeof(uuid_t));
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, peer->context_type);
    my_cbuffer_push_back(&peer->out_buf, peer->context, sizeof(uuid_t));
}
