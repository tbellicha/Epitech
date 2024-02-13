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

static const size_t MAX_COMMENT_LENGTH = sizeof(uuid_t) + 1 + MAX_BODY_LENGTH;
static const size_t MAX_COMMENT_TMP_BUFFER =
    PEER_BUFFER_SIZE - MAX_COMMENT_LENGTH;

static uint32_t reply_comment_list_write(
    comment_list_t *comments, char *buf, uint32_t *count)
{
    uint32_t offset = 0;
    comment_t *comment = LIST_FIRST(comments);
    size_t body_length;

    while (comment && offset < MAX_COMMENT_TMP_BUFFER) {
        memcpy(buf + offset, comment->header.id, sizeof(uuid_t));
        offset += sizeof(uuid_t);
        offset += uleb128_encode_64(buf + offset, comment->header.timestamp);
        memcpy(buf + offset, comment->header.creator, sizeof(uuid_t));
        offset += sizeof(uuid_t);
        body_length = strlen(comment->body);
        offset += uleb128_encode_32(buf + offset, body_length);
        memcpy(buf + offset, comment->body, body_length);
        offset += body_length;
        comment = LIST_NEXT(comment, comments);
        ++(*count);
    }
    return offset;
}

/// @returns NULL if channel is not valid, the channel otherwise
static thread_t *get_thread_searched(
    peer_t *peer, uuid_t team_id, uuid_t channel_id, uuid_t thread_id)
{
    team_t *team = server_find_team(peer->server, team_id);
    channel_t *channel;
    thread_t *thread;

    if (team == NULL) {
        reply_unknown_item(peer, team_id, REPLY_UNKNOWN_TEAM);
        return NULL;
    }
    channel = server_find_channel_inner(team, channel_id);
    if (channel == NULL) {
        reply_unknown_item(peer, channel_id, REPLY_UNKNOWN_CHANNEL);
        return NULL;
    }
    thread = server_find_thread_inner2(channel, thread_id);
    if (thread == NULL) {
        reply_unknown_item(peer, thread_id, REPLY_UNKNOWN_THREAD);
        return NULL;
    }
    return thread;
}

void reply_comment_list(
    peer_t *peer, uuid_t team_id, uuid_t channel_id, uuid_t thread_id)
{
    uint32_t count = 0;
    uint32_t msgs_size;
    uint32_t count_size;
    thread_t *thread =
        get_thread_searched(peer, team_id, channel_id, thread_id);

    if (thread == NULL)
        return;
    msgs_size =
        reply_comment_list_write(&thread->comments, peer->tmp_buffer, &count);
    count_size = uleb128_size_32(count) + sizeof(uuid_t);
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, S2C_COMMENT_LIST);
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, count_size + msgs_size);
    my_cbuffer_push_back(&peer->out_buf, thread_id, sizeof(uuid_t));
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, count);
    my_cbuffer_push_back(&peer->out_buf, peer->tmp_buffer, msgs_size);
}
