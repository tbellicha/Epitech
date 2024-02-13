/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Server initialization
*/

#include "items/team.h"
#include "protocol.h"
#include "server.h"

#include <netinet/in.h>
#include <stdbool.h>
#include <string.h>

bool server_init(server_t *server, uint16_t port)
{
    LIST_INIT(&server->peers);
    FD_ZERO(&server->poll_fds_in);
    FD_ZERO(&server->poll_fds_out);
    LIST_INIT(&server->teams);
    LIST_INIT(&server->users);
    server_init_messages_map(&server->messages);
    return socket_listen(&server->socket, port);
}
