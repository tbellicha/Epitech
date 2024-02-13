/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Server cycle
*/

#include "server.h"
#include "packet_handlers.h"

#include <errno.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

static void server_accept_peer(server_t *server)
{
    int fd;
    struct sockaddr_in address;
    socklen_t address_len = sizeof(address);
    peer_t *new_peer;

    fd = accept(server->socket, (struct sockaddr *)&address, &address_len);
    if (fd == -1) {
        printf("Connection failed: %s\n", strerror(errno));
        return;
    }
    new_peer = peer_create(fd, &address);
    if (!new_peer) {
        close(fd);
        return;
    }
    new_peer->server = server;
    LIST_INSERT_HEAD(&server->peers, new_peer, peers);
    peer_log(new_peer, "Connected");
}

static void server_peer_cycle(server_t *server, peer_t **peer)
{
    if (server_peer_in_ready(server, *peer))
        peer_read_input(peer);
    if (*peer && server_peer_out_ready(server, *peer))
        peer_write_output(peer);
    while (*peer && (*peer)->in_buf.len > 0
        && handle_packet(*peer) == PRESULT_OK)
        ;
}

void server_cycle(server_t *server)
{
    peer_t *peer;
    peer_t *next;

    if (!server_poll(server))
        return;
    if (server_connection_ready(server)) {
        puts("Accepting inbound connection");
        server_accept_peer(server);
    }
    peer = LIST_FIRST(&server->peers);
    while (peer) {
        next = LIST_NEXT(peer, peers);
        server_peer_cycle(server, &peer);
        peer = next;
    }
}
