/*
** EPITECH PROJECT, 2022
** MyChannels
** File description:
** channel_created
*/

#include "cbuffer.h"
#include "items/channel.h"
#include "items/team.h"
#include "leb128.h"
#include "peer.h"
#include "protocol.h"

#include <stdint.h>
#include <string.h>

/// Writes the content of the S2C_CHANNEL_CREATED packet into a temporary
/// buffer.
static uint32_t encode_channel_created_packet(char *buf, channel_t *channel)
{
    uint32_t name_length = strlen(channel->name);
    uint32_t desc_length = strlen(channel->desc);
    uint32_t offset = uleb128_encode_64(buf, channel->header.timestamp);

    memcpy(buf + offset, channel->header.creator, sizeof(uuid_t));
    offset += sizeof(uuid_t);
    memcpy(buf + offset, channel->team->header.id, sizeof(uuid_t));
    offset += sizeof(uuid_t);
    memcpy(buf + offset, channel->header.id, sizeof(uuid_t));
    offset += sizeof(uuid_t);
    offset += uleb128_encode_32(buf + offset, name_length);
    memcpy(buf + offset, channel->name, name_length);
    offset += name_length;
    memcpy(buf + offset, channel->desc, desc_length);
    offset += desc_length;
    return offset;
}

void reply_channel_created(peer_t *peer, channel_t *channel)
{
    uint32_t packet_len =
        encode_channel_created_packet(peer->tmp_buffer, channel);

    my_cbuffer_push_back_uleb128_32(&peer->out_buf, S2C_CHANNEL_CREATED);
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, packet_len);
    my_cbuffer_push_back(&peer->out_buf, &peer->tmp_buffer, packet_len);
}
