/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** comment_created
*/

#include "cbuffer.h"
#include "items/comment.h"
#include "items/team.h"
#include "leb128.h"
#include "peer.h"
#include "protocol.h"

#include <stdint.h>
#include <string.h>

/// Writes the content of the S2C_COMMENT_CREATED packet into a temporary
/// buffer.
static uint32_t encode_comment_created_packet(char *buf, comment_t *comment)
{
    uint32_t body_length = strlen(comment->body);
    uint32_t offset = uleb128_encode_64(buf, comment->header.timestamp);

    memcpy(buf + offset, comment->header.creator, sizeof(uuid_t));
    offset += sizeof(uuid_t);
    memcpy(buf + offset, comment->thread->channel->team->header.id,
        sizeof(uuid_t));
    offset += sizeof(uuid_t);
    memcpy(buf + offset, comment->thread->channel->header.id, sizeof(uuid_t));
    offset += sizeof(uuid_t);
    memcpy(buf + offset, comment->thread->header.id, sizeof(uuid_t));
    offset += sizeof(uuid_t);
    memcpy(buf + offset, comment->header.id, sizeof(uuid_t));
    offset += sizeof(uuid_t);
    memcpy(buf + offset, comment->body, body_length);
    offset += body_length;
    return offset;
}

void reply_comment_created(peer_t *peer, comment_t *comment)
{
    uint32_t packet_len =
        encode_comment_created_packet(peer->tmp_buffer, comment);

    my_cbuffer_push_back_uleb128_32(&peer->out_buf, S2C_COMMENT_CREATED);
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, packet_len);
    my_cbuffer_push_back(&peer->out_buf, &peer->tmp_buffer, packet_len);
}
