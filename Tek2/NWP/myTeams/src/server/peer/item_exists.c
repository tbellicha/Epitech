/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** item_exists
*/

#include "peer.h"
#include "server.h"

#include <stdbool.h>

static void *peer_item_exists_inner(
    server_t *server, context_type_t context_type, uuid_t id)
{
    switch (context_type) {
        case CONTEXT_NONE: return server_find_team(server, id);
        case CONTEXT_TEAM: return server_find_channel(server, id);
        case CONTEXT_CHANNEL: return server_find_thread(server, id);
        case CONTEXT_THREAD:
        default: return NULL;
    }
}

bool peer_item_exists(peer_t *peer, uuid_t id)
{
    return !!peer_item_exists_inner(peer->server, peer->context_type, id);
}

static void *peer_item_exists_by_name_inner(
    server_t *server, context_type_t context_type, char const *name)
{
    switch (context_type) {
        case CONTEXT_NONE: return server_find_team_by_name(server, name);
        case CONTEXT_TEAM: return server_find_channel_by_name(server, name);
        case CONTEXT_CHANNEL:
            return server_find_thread_by_title(server, name);
        case CONTEXT_THREAD:
        default: return NULL;
    }
}

bool peer_item_exists_by_name(peer_t *peer, char const *name)
{
    return !!peer_item_exists_by_name_inner(
        peer->server, peer->context_type, name);
}
