/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** create_channel
*/

#include "items/channel.h"
#include "items/team.h"
#include "peer.h"
#include "server.h"
#include "logging_server.h"
#include "packet_reply.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static void notify_channel_creation(peer_t *peer, channel_t *channel)
{
    server_t *server = peer->server;

    server_event_channel_created(
        channel->team->header.id_str, channel->header.id_str, channel->name);
    peer_log(peer,
        "Created channel '%s' (%.8s) in '%s' (%.8s), with description '%s'",
        channel->name, channel->header.id_str, channel->team->name,
        channel->team->header.id_str, channel->desc);
    for (peer_t *p = LIST_FIRST(&server->peers); p; p = LIST_NEXT(p, peers)) {
        if (peer_is_subscribed(p, channel->team))
            reply_channel_created(p, channel);
    }
}

static bool check_subscribed(peer_t *peer, team_t *team, channel_t *channel)
{
    if (!peer_is_subscribed(peer, team)) {
        reply_error(peer, REPLY_NOT_SUBSCRIBED,
            "you are not subscribed to this team", 0);
        free(channel);
        return false;
    }
    return true;
}

bool peer_create_channel(
    peer_t *peer, uuid_t team_id, char const *name, char const *description)
{
    team_t *team = server_find_team(peer->server, team_id);
    channel_t *channel = calloc(sizeof(*channel), 1);

    if (!team || !channel) {
        free(channel);
        return false;
    }
    if (!check_subscribed(peer, team, channel))
        return true;
    peer_init_item_header(peer, &channel->header);
    channel->team = team;
    LIST_INIT(&channel->threads);
    strncpy(channel->name, name, MAX_NAME_LENGTH);
    strncpy(channel->desc, description, MAX_DESCRIPTION_LENGTH);
    LIST_INSERT_HEAD(&team->channels, channel, channels);
    notify_channel_creation(peer, channel);
    return true;
}
