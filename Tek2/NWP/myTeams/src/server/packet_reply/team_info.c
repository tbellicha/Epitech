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

static uint32_t reply_team_info_write(team_t *team, char *buf)
{
    size_t name_length;
    size_t desc_length;
    uint32_t offset = 0;

    memcpy(buf + offset, team->header.id, sizeof(uuid_t));
    offset += sizeof(uuid_t);
    offset += uleb128_encode_64(buf + offset, team->header.timestamp);
    memcpy(buf + offset, team->header.creator, sizeof(uuid_t));
    offset += sizeof(uuid_t);
    name_length = strlen(team->name);
    offset += uleb128_encode_32(buf + offset, name_length);
    memcpy(buf + offset, team->name, name_length);
    offset += name_length;
    desc_length = strlen(team->desc);
    memcpy(buf + offset, team->desc, desc_length);
    offset += desc_length;
    return offset;
}

void reply_team_info(peer_t *peer, uuid_t id, size_t length)
{
    team_t *team = server_find_team(peer->server, id);
    uint32_t msgs_size;

    if (!team) {
        reply_error(peer, REPLY_UNKNOWN_TEAM, "unknown team", length);
        return;
    }
    msgs_size = reply_team_info_write(team, peer->tmp_buffer);
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, S2C_TEAM_INFO);
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, msgs_size);
    my_cbuffer_push_back(&peer->out_buf, peer->tmp_buffer, msgs_size);
}
