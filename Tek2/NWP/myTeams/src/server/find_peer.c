/*
** EPITECH PROJECT, 2022
** Myteams
** File description:
** find_peer
*/

#include "peer.h"
#include "server.h"

peer_t *server_find_peer(server_t *server, uuid_t id)
{
    peer_t *dst_peer = LIST_FIRST(&server->peers);

    while (dst_peer) {
        if (uuid_compare(dst_peer->user->id, id) == 0)
            return dst_peer;
        dst_peer = LIST_NEXT(dst_peer, peers);
    }
    return NULL;
}
