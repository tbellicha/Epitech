/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** S2C_THREAD_LIST
*/

#include "items/team.h"
#include "leb128.h"
#include "peer.h"
#include "server.h"
#include "util.h"
#include "hash_map.h"
#include "packet_handlers.h"
#include "packet_reply.h"

#include <stdbool.h>
#include <string.h>
#include <uuid/uuid.h>

static const size_t MAX_THREAD_LENGTH =
    sizeof(uuid_t) + 1 + MAX_NAME_LENGTH + 2 + MAX_BODY_LENGTH;
static const size_t MAX_THREAD_TMP_BUFFER =
    PEER_BUFFER_SIZE - MAX_THREAD_LENGTH;

static void reply_thread_write(thread_t *thread, char *buf, uint32_t *offset)
{
    size_t title_length;
    size_t desc_length;

    memcpy(buf + *offset, thread->header.id, sizeof(uuid_t));
    *offset += sizeof(uuid_t);
    *offset += uleb128_encode_64(buf + *offset, thread->header.timestamp);
    memcpy(buf + *offset, thread->header.creator, sizeof(uuid_t));
    *offset += sizeof(uuid_t);
    title_length = strlen(thread->title);
    *offset += uleb128_encode_32(buf + *offset, title_length);
    memcpy(buf + *offset, thread->title, title_length);
    *offset += title_length;
    desc_length = strlen(thread->body);
    *offset += uleb128_encode_32(buf + *offset, desc_length);
    memcpy(buf + *offset, thread->body, desc_length);
    *offset += desc_length;
}

static uint32_t reply_thread_list_write(
    thread_list_t *threads, char *buf, uint32_t *count)
{
    uint32_t offset = 0;
    thread_t *thread = LIST_FIRST(threads);

    while (thread && offset < MAX_THREAD_TMP_BUFFER) {
        reply_thread_write(thread, buf, &offset);
        thread = LIST_NEXT(thread, threads);
        ++(*count);
    }
    return offset;
}

/// @returns NULL if channel is not valid, the channel otherwise
static channel_t *get_channel_searched(
    peer_t *peer, uuid_t team_id, uuid_t channel_id)
{
    team_t *team = server_find_team(peer->server, team_id);
    channel_t *channel;

    if (team == NULL) {
        reply_unknown_item(peer, team_id, REPLY_UNKNOWN_TEAM);
        return NULL;
    }
    channel = server_find_channel_inner(team, channel_id);
    if (channel == NULL) {
        reply_unknown_item(peer, channel_id, REPLY_UNKNOWN_CHANNEL);
        return NULL;
    }
    return channel;
}

void reply_thread_list(peer_t *peer, uuid_t team_id, uuid_t channel_id)
{
    uint32_t count = 0;
    uint32_t msgs_size;
    uint32_t count_size;
    channel_t *channel = get_channel_searched(peer, team_id, channel_id);

    if (channel == NULL)
        return;
    msgs_size =
        reply_thread_list_write(&channel->threads, peer->tmp_buffer, &count);
    count_size = uleb128_size_32(count);
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, S2C_THREAD_LIST);
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, count_size + msgs_size);
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, count);
    my_cbuffer_push_back(&peer->out_buf, peer->tmp_buffer, msgs_size);
}
