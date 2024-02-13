/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** thread_created
*/

#include "cbuffer.h"
#include "items/team.h"
#include "items/thread.h"
#include "leb128.h"
#include "peer.h"
#include "protocol.h"

#include <stdint.h>
#include <string.h>

/// Writes the content of the S2C_THREAD_CREATED packet into a temporary
/// buffer.
static uint32_t encode_thread_created_packet(char *buf, thread_t *thread)
{
    uint32_t title_length = strlen(thread->title);
    uint32_t body_length = strlen(thread->body);
    uint32_t offset = uleb128_encode_64(buf, thread->header.timestamp);

    memcpy(buf + offset, thread->header.creator, sizeof(uuid_t));
    offset += sizeof(uuid_t);
    memcpy(buf + offset, thread->channel->team->header.id, sizeof(uuid_t));
    offset += sizeof(uuid_t);
    memcpy(buf + offset, thread->channel->header.id, sizeof(uuid_t));
    offset += sizeof(uuid_t);
    memcpy(buf + offset, thread->header.id, sizeof(uuid_t));
    offset += sizeof(uuid_t);
    offset += uleb128_encode_32(buf + offset, title_length);
    memcpy(buf + offset, thread->title, title_length);
    offset += title_length;
    memcpy(buf + offset, thread->body, body_length);
    offset += body_length;
    return offset;
}

void reply_thread_created(peer_t *peer, thread_t *thread)
{
    uint32_t packet_len =
        encode_thread_created_packet(peer->tmp_buffer, thread);

    my_cbuffer_push_back_uleb128_32(&peer->out_buf, S2C_THREAD_CREATED);
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, packet_len);
    my_cbuffer_push_back(&peer->out_buf, &peer->tmp_buffer, packet_len);
}
