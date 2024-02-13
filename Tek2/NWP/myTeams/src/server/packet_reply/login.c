/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** generic packet
*/

#include "leb128.h"
#include "peer.h"
#include "protocol.h"

#include <string.h>

void reply_login_logout(
    peer_t *peer, uuid_t id, char const *name, s2c_packet_id_t type)
{
    size_t name_length = name ? strlen(name) : 0;

    my_cbuffer_push_back_uleb128_32(&peer->out_buf, type);
    my_cbuffer_push_back_uleb128_32(
        &peer->out_buf, name_length + sizeof(uuid_t));
    my_cbuffer_push_back(&peer->out_buf, id, sizeof(uuid_t));
    if (name)
        my_cbuffer_push_back(&peer->out_buf, name, name_length);
}

void reply_login(peer_t *peer, uuid_t id, char const *name)
{
    reply_login_logout(peer, id, name, S2C_LOGIN);
}
