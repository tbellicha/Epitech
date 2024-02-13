/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** S2C_TEAM_LIST
*/

#include "items/team.h"
#include "leb128.h"
#include "peer.h"
#include "server.h"
#include "util.h"
#include "packet_reply.h"

#include <string.h>
#include <uuid/uuid.h>

static const size_t MAX_USER_LENGTH =
    sizeof(uuid_t) + 1 + MAX_NAME_LENGTH + 1;
static const size_t MAX_USER_TMP_BUFFER = PEER_BUFFER_SIZE - MAX_USER_LENGTH;

static uint32_t reply_team_users_list_write(
    team_subscriber_list_t *subs, char *buf, uint32_t *count)
{
    uint32_t offset = 0;
    team_subscriber_t *sub = subs ? LIST_FIRST(subs) : NULL;
    size_t name_length;

    while (sub && offset < MAX_USER_TMP_BUFFER) {
        memcpy(buf + offset, sub->user->id, sizeof(uuid_t));
        offset += sizeof(uuid_t);
        name_length = strlen(sub->user->name);
        offset += uleb128_encode_32(buf + offset, name_length);
        memcpy(buf + offset, sub->user->name, name_length);
        offset += name_length;
        offset += uleb128_encode_32(
            buf + offset, !LIST_EMPTY(&sub->user->sessions));
        sub = LIST_NEXT(sub, subscribers);
        ++(*count);
    }
    return offset;
}

void reply_team_users_list(peer_t *peer, uuid_t id, size_t length)
{
    team_t *team = server_find_team(peer->server, id);
    uint32_t count = 0;
    uint32_t msgs_size = 0;
    uint32_t count_size = 0;

    if (!team) {
        reply_error(peer, REPLY_UNKNOWN_TEAM, "unknown team", length);
        return;
    }
    msgs_size = reply_team_users_list_write(
        &team->subscribers, peer->tmp_buffer, &count);
    count_size = uleb128_size_32(count);

    my_cbuffer_push_back_uleb128_32(&peer->out_buf, S2C_USER_LIST);
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, count_size + msgs_size);
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, count);
    my_cbuffer_push_back(&peer->out_buf, peer->tmp_buffer, msgs_size);
}
