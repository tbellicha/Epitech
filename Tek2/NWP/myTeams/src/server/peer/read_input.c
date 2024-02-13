/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Reads input from a peer
*/

#include "peer.h"

#include <errno.h>
#include <string.h>
#include <unistd.h>

void peer_read_input(peer_t **peer)
{
    ssize_t ret =
        read((*peer)->fd, (*peer)->tmp_buffer, peer_buffer_remaining(*peer));

    if (ret > 0) {
        my_cbuffer_push_back(&(*peer)->in_buf, (*peer)->tmp_buffer, ret);
        return;
    }
    LIST_REMOVE(*peer, peers);
    if (ret < 0)
        peer_log(*peer, "Connection closed (%s)", strerror(errno));
    else
        peer_log(*peer, "Connection closed (input closed)");
    peer_destroy(*peer, true);
    *peer = NULL;
}
