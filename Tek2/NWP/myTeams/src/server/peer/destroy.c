/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Server peers
*/

#include "peer.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void peer_destroy(peer_t *peer, bool print_logout_message)
{
    if (!peer)
        return;
    peer_unset_user(peer, print_logout_message);
    close(peer->fd);
    peer->fd = -1;
    peer->user = NULL;
    peer->peers.le_prev = NULL;
    peer->peers.le_next = NULL;
    free(peer);
}
