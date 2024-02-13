/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** create_team
*/

#include "items/team.h"
#include "peer.h"
#include "server.h"
#include "logging_server.h"
#include "packet_reply.h"

#include <stdlib.h>
#include <string.h>

static void notify_team_creation(peer_t *peer, team_t *team)
{
    server_t *server = peer->server;

    server_event_team_created(
        team->header.id_str, team->name, team->header.creator_str);
    peer_log(peer, "Created team '%s' (%.8s) with description '%s'",
        team->name, team->header.id_str, team->desc);
    for (peer_t *p = LIST_FIRST(&server->peers); p; p = LIST_NEXT(p, peers)) {
        if (p->user)
            reply_team_created(p, team);
    }
}

bool peer_create_team(
    peer_t *peer, uuid_t unused, char const *name, char const *description)
{
    team_t *team = calloc(sizeof(*team), 1);

    (void)unused;
    if (!team)
        return false;
    peer_init_item_header(peer, &team->header);
    LIST_INIT(&team->channels);
    LIST_INIT(&team->subscribers);
    strncpy(team->name, name, MAX_NAME_LENGTH);
    strncpy(team->desc, description, MAX_DESCRIPTION_LENGTH);
    LIST_INSERT_HEAD(&peer->server->teams, team, teams);
    notify_team_creation(peer, team);
    return true;
}
