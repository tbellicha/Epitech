/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** team_created
*/

#include "cbuffer.h"
#include "items/team.h"
#include "leb128.h"
#include "peer.h"
#include "protocol.h"

#include <stdint.h>
#include <string.h>

/// Writes the content of the S2C_TEAM_CREATED packet into a temporary buffer.
static uint32_t encode_team_created_packet(char *buf, team_t *team)
{
    uint32_t name_length = strlen(team->name);
    uint32_t desc_length = strlen(team->desc);
    uint32_t offset = uleb128_encode_64(buf, team->header.timestamp);

    memcpy(buf + offset, team->header.creator, sizeof(uuid_t));
    offset += sizeof(uuid_t);
    memcpy(buf + offset, team->header.id, sizeof(uuid_t));
    offset += sizeof(uuid_t);
    offset += uleb128_encode_32(buf + offset, name_length);
    memcpy(buf + offset, team->name, name_length);
    offset += name_length;
    memcpy(buf + offset, team->desc, desc_length);
    offset += desc_length;
    return offset;
}

void reply_team_created(peer_t *peer, team_t *team)
{
    uint32_t packet_len = encode_team_created_packet(peer->tmp_buffer, team);

    my_cbuffer_push_back_uleb128_32(&peer->out_buf, S2C_TEAM_CREATED);
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, packet_len);
    my_cbuffer_push_back(&peer->out_buf, &peer->tmp_buffer, packet_len);
}
