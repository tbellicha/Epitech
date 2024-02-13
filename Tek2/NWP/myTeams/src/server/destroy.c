/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Server destruction
*/

#include "server.h"
#include "hash_map.h"

#include <stdlib.h>
#include <sys/queue.h>

static void server_destroy_peers(server_t *server)
{
    peer_t *peer;
    peer_t *next;

    peer = LIST_FIRST(&server->peers);
    while (peer) {
        next = LIST_NEXT(peer, peers);
        peer_destroy(peer, false);
        peer = next;
    }
}

static void server_destroy_users(server_t *server)
{
    user_t *user;
    user_t *next;

    user = LIST_FIRST(&server->users);
    while (user) {
        next = LIST_NEXT(user, users);
        free(user);
        user = next;
    }
}

void server_destroy(server_t *server)
{
    socket_close(server->socket);
    server_destroy_peers(server);
    server_destroy_teams(server);
    server_destroy_users(server);
    my_hash_map_drop(&server->messages);
}
