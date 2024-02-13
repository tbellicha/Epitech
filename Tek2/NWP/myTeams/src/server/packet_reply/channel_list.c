/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** S2C_CHANNEL_LIST
*/

#include "items/team.h"
#include "leb128.h"
#include "peer.h"
#include "server.h"
#include "util.h"
#include "hash_map.h"
#include "packet_handlers.h"
#include "packet_reply.h"

#include <string.h>
#include <uuid/uuid.h>

static const size_t MAX_CHANNEL_LENGTH =
    sizeof(uuid_t) + 1 + MAX_NAME_LENGTH + 2 + MAX_DESCRIPTION_LENGTH;
static const size_t MAX_CHANNEL_TMP_BUFFER =
    PEER_BUFFER_SIZE - MAX_CHANNEL_LENGTH;

static uint32_t reply_channel_list_write(
    channel_list_t *channels, char *buf, uint32_t *count)
{
    uint32_t offset = 0;
    channel_t *channel = LIST_FIRST(channels);
    size_t name_length;
    size_t desc_length;

    while (channel && offset < MAX_CHANNEL_TMP_BUFFER) {
        memcpy(buf + offset, channel->header.id, sizeof(uuid_t));
        offset += sizeof(uuid_t);
        name_length = strlen(channel->name);
        offset += uleb128_encode_32(buf + offset, name_length);
        memcpy(buf + offset, channel->name, name_length);
        offset += name_length;
        desc_length = strlen(channel->desc);
        offset += uleb128_encode_32(buf + offset, desc_length);
        memcpy(buf + offset, channel->desc, desc_length);
        offset += desc_length;
        channel = LIST_NEXT(channel, channels);
        ++(*count);
    }
    return offset;
}

void reply_channel_list(peer_t *peer, uuid_t team_id)
{
    team_t *team = server_find_team(peer->server, team_id);
    uint32_t count = 0;
    uint32_t msgs_size;
    uint32_t count_size;

    if (team == NULL) {
        reply_unknown_item(peer, team_id, REPLY_UNKNOWN_TEAM);
        return;
    }
    msgs_size =
        reply_channel_list_write(&team->channels, peer->tmp_buffer, &count);
    count_size = uleb128_size_32(count);
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, S2C_CHANNEL_LIST);
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, count_size + msgs_size);
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, count);
    my_cbuffer_push_back(&peer->out_buf, peer->tmp_buffer, msgs_size);
}
