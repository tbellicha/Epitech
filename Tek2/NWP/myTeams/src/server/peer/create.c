/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Server peers
*/

#include "items/user.h"
#include "peer.h"

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

peer_t *peer_create(int fd, struct sockaddr_in const *address)
{
    peer_t *peer = malloc(sizeof(*peer));

    if (!peer)
        return NULL;
    peer->fd = fd;
    if (address)
        memcpy(&peer->address, address, sizeof(*address));
    else
        memset(&peer->address, 0, sizeof(*address));
    peer->user = NULL;
    memset(peer->raw_in_buf, 0, PEER_BUFFER_SIZE);
    memset(peer->raw_out_buf, 0, PEER_BUFFER_SIZE);
    my_cbuffer_init(&peer->in_buf, peer->raw_in_buf, PEER_BUFFER_SIZE);
    my_cbuffer_init(&peer->out_buf, peer->raw_out_buf, PEER_BUFFER_SIZE);
    peer->peers.le_prev = NULL;
    peer->peers.le_next = NULL;
    uuid_clear(peer->context);
    peer->context_type = CONTEXT_NONE;
    return peer;
}
