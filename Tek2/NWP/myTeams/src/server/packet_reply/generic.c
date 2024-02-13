/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** generic packet
*/

#include "leb128.h"
#include "peer.h"
#include "packet_reply.h"

#include <string.h>

void reply_generic(peer_t *peer, reply_code_t code, char const *description)
{
    size_t code_length = uleb128_size_32(code);
    size_t desc_length = strlen(description);

    my_cbuffer_push_back_uleb128_32(&peer->out_buf, S2C_GENERIC);
    my_cbuffer_push_back_uleb128_32(
        &peer->out_buf, code_length + desc_length);
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, code);
    my_cbuffer_push_back(&peer->out_buf, description, desc_length);
}
