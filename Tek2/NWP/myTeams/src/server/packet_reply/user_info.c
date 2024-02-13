/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** S2C_USER_LIST
*/

#include "items/user.h"
#include "leb128.h"
#include "peer.h"
#include "protocol.h"
#include "server.h"
#include "packet_reply.h"

#include <string.h>

static uint32_t reply_user_write_info(peer_t *peer, user_t *user)
{
    uint32_t offset = 0;
    size_t name_length;
    char *buf = (char *)peer->tmp_buffer;

    memcpy(buf + offset, user->id, sizeof(uuid_t));
    name_length = strlen(user->name);
    offset += sizeof(uuid_t);
    offset += uleb128_encode_64(buf + offset, user->timestamp);
    offset += uleb128_encode_32(buf + offset, !LIST_EMPTY(&user->sessions));
    memcpy(buf + offset, user->name, name_length);
    offset += name_length;
    return offset;
}

void reply_user_info(peer_t *peer, uuid_t user_id)
{
    uint32_t user_size;
    user_t *user = server_find_user(peer->server, user_id);

    if (!user) {
        reply_unknown_item(peer, user_id, REPLY_UNKNOWN_USER);
        return;
    }
    user_size = reply_user_write_info(peer, user);
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, S2C_USER_INFO);
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, user_size);
    my_cbuffer_push_back(&peer->out_buf, peer->tmp_buffer, user_size);
}
