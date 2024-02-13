/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** S2C_UNSUBSCRIBED
*/

#include "peer.h"
#include "protocol.h"

void reply_unsubscribed(peer_t *peer, uuid_t team_id)
{
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, S2C_UNSUBSCRIBED);
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, sizeof(uuid_t));
    my_cbuffer_push_back(&peer->out_buf, team_id, sizeof(uuid_t));
}
