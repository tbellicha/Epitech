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
#include "hash_map.h"

#include <stdbool.h>
#include <string.h>
#include <uuid/uuid.h>

static const size_t MAX_TEAM_LENGTH =
    sizeof(uuid_t) + 1 + MAX_NAME_LENGTH + 2 + MAX_DESCRIPTION_LENGTH;
static const size_t MAX_TEAM_TMP_BUFFER = PEER_BUFFER_SIZE - MAX_TEAM_LENGTH;

static void reply_team_write(team_t *team, char *buf, uint32_t *offset)
{
    size_t name_length;
    size_t desc_length;

    memcpy(buf + *offset, team->header.id, sizeof(uuid_t));
    *offset += sizeof(uuid_t);
    name_length = strlen(team->name);
    *offset += uleb128_encode_32(buf + *offset, name_length);
    memcpy(buf + *offset, team->name, name_length);
    *offset += name_length;
    desc_length = strlen(team->desc);
    *offset += uleb128_encode_32(buf + *offset, desc_length);
    memcpy(buf + *offset, team->desc, desc_length);
    *offset += desc_length;
}

static uint32_t reply_team_list_write(
    team_list_t *teams, peer_t *peer, uint32_t *count, bool filter_subscribed)
{
    char *buf = peer->tmp_buffer;
    uint32_t offset = 0;
    team_t *team = teams ? LIST_FIRST(teams) : NULL;

    while (team && offset < MAX_TEAM_TMP_BUFFER) {
        if (!filter_subscribed || peer_is_subscribed(peer, team)) {
            reply_team_write(team, buf, &offset);
            ++(*count);
        }
        team = LIST_NEXT(team, teams);
    }
    return offset;
}

void reply_team_list(peer_t *peer, bool filter_subscribed)
{
    team_list_t *teams = &peer->server->teams;
    uint32_t count = 0;
    uint32_t msgs_size =
        reply_team_list_write(teams, peer, &count, filter_subscribed);
    uint32_t count_size = uleb128_size_32(count);

    my_cbuffer_push_back_uleb128_32(&peer->out_buf, S2C_TEAM_LIST);
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, count_size + msgs_size);
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, count);
    my_cbuffer_push_back(&peer->out_buf, peer->tmp_buffer, msgs_size);
}
