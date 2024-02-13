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
#include "logging_server.h"

#include <string.h>

static const size_t MAX_USER_LENGTH =
    sizeof(uuid_t) + 1 + MAX_NAME_LENGTH + 1;
static const size_t MAX_USER_TMP_BUFFER = PEER_BUFFER_SIZE - MAX_USER_LENGTH;

static uint32_t reply_user_list_write_users(peer_t *peer, uint32_t *count)
{
    uint32_t offset = 0;
    size_t name_length;
    user_t *user = LIST_FIRST(&peer->server->users);
    char *buf = (char *)peer->tmp_buffer;

    while (offset < MAX_USER_TMP_BUFFER && user) {
        memcpy(buf + offset, user->id, sizeof(uuid_t));
        name_length = strlen(user->name);
        offset += sizeof(uuid_t);
        offset += uleb128_encode_32(buf + offset, name_length);
        memcpy(buf + offset, user->name, name_length);
        offset += name_length;
        offset +=
            uleb128_encode_32(buf + offset, !LIST_EMPTY(&user->sessions));
        ++*(count);
        user = LIST_NEXT(user, users);
    }
    return offset;
}

void reply_user_list(peer_t *peer)
{
    uint32_t count = 0;
    uint32_t users_size = reply_user_list_write_users(peer, &count);
    uint32_t count_size = uleb128_size_32(count);

    my_cbuffer_push_back_uleb128_32(&peer->out_buf, S2C_USER_LIST);
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, count_size + users_size);
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, count);
    my_cbuffer_push_back(&peer->out_buf, peer->tmp_buffer, users_size);
}
