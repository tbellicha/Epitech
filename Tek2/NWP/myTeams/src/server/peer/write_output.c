/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Writes output to a peer
*/

#include "peer.h"

#include <errno.h>
#include <string.h>
#include <unistd.h>

void peer_write_output(peer_t **peer)
{
    ssize_t ret = my_cbuffer_pop_front_to(&(*peer)->out_buf, (*peer)->fd);

    if (ret > 0)
        return;
    LIST_REMOVE(*peer, peers);
    if (ret < 0)
        peer_log(*peer, "Connection closed (%s)", strerror(errno));
    else
        peer_log(*peer, "Connection closed (output closed)");
    peer_destroy(*peer, true);
    *peer = NULL;
}
