/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** S2C_UNKNOWN_ITEM
*/

#include "leb128.h"
#include "peer.h"
#include "protocol.h"

void reply_unknown_item(peer_t *peer, uuid_t id, reply_code_t reply_code)
{
    char buf[5];
    size_t length_reply_code = uleb128_encode_32(buf, reply_code);

    my_cbuffer_push_back_uleb128_32(&peer->out_buf, S2C_UNKNOWN_ITEM);
    my_cbuffer_push_back_uleb128_32(
        &peer->out_buf, sizeof(uuid_t) + length_reply_code);
    my_cbuffer_push_back(&peer->out_buf, buf, length_reply_code);
    my_cbuffer_push_back(&peer->out_buf, id, sizeof(uuid_t));
}
