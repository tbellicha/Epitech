/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Inbound connections and packets polling
*/

#include "server.h"

#include <stdbool.h>
#include <stddef.h>
#include <sys/select.h>

/// Checks for inbound connections or packets.
bool server_poll(server_t *server)
{
    fd_set *fds_in = &server->poll_fds_in;
    fd_set *fds_out = &server->poll_fds_out;
    int nfds = server->socket;
    struct timeval timeout = {.tv_sec = 0, .tv_usec = 50000};

    FD_ZERO(fds_in);
    FD_ZERO(fds_out);
    FD_SET(server->socket, fds_in);
    for (peer_t *p = LIST_FIRST(&server->peers); p; p = LIST_NEXT(p, peers)) {
        nfds = p->fd > nfds ? p->fd : nfds;
        FD_SET(p->fd, fds_in);
        if (p->out_buf.len > 0)
            FD_SET(p->fd, fds_out);
    }
    return select(nfds + 1, fds_in, fds_out, NULL, &timeout) > 0;
}

bool server_connection_ready(server_t const *server)
{
    return FD_ISSET(server->socket, &server->poll_fds_in);
}

bool server_peer_in_ready(server_t const *restrict server, peer_t const *peer)
{
    return peer->fd != -1 && peer_buffer_remaining(peer) > 0
        && FD_ISSET(peer->fd, &server->poll_fds_in);
}

bool server_peer_out_ready(
    server_t const *restrict server, peer_t const *peer)
{
    return peer->fd != -1 && peer->out_buf.len > 0
        && FD_ISSET(peer->fd, &server->poll_fds_out);
}
