/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Receive team unsubscription client packet
*/

#include "items/team.h"
#include "peer.h"
#include "server.h"
#include "logging_server.h"
#include "packet_handlers.h"
#include "packet_reply.h"

#include <stdlib.h>

static void unsubscribe_user(peer_t *peer, team_t *team)
{
    team_subscriber_t *sub = LIST_FIRST(&team->subscribers);

    while (sub && sub->user != peer->user)
        sub = LIST_NEXT(sub, subscribers);
    if (sub == NULL)
        return;
    LIST_REMOVE(sub, subscribers);
    free(sub);
    return;
}

static packet_result_t notify_unsubscription(peer_t *peer, team_t *team)
{
    server_event_user_unsubscribed(team->header.id_str, peer->user->id_str);
    reply_unsubscribed(peer, team->header.id);
    return PRESULT_OK;
}

packet_result_t handle_unsubscribe_team_packet(peer_t *peer, size_t length)
{
    uuid_t team_id;
    team_t *team;

    if (!peer_check_logged_in(peer, length))
        return PRESULT_OK;
    if (length != sizeof(uuid_t)) {
        reply_error(peer, REPLY_INVALID_LENGTH,
            "subscribe requires a valid team", length);
        return PRESULT_OK;
    }
    my_cbuffer_pop_front(&peer->in_buf, &team_id, sizeof(uuid_t));
    team = server_find_team(peer->server, team_id);
    if (!team) {
        reply_unknown_item(peer, team_id, REPLY_UNKNOWN_TEAM);
        return PRESULT_OK;
    }
    unsubscribe_user(peer, team);
    return notify_unsubscription(peer, team);
}
