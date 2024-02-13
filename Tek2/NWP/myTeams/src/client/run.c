/*
** EPITECH PROJECT, 2022
** Project
** File description:
** run
*/

#include "client.h"
#include "commands/commands.h"
#include "util.h"
#include "packet_handlers/server_packet_handlers.h"

#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

static void greet_client(client_t const *client)
{
    if (!client->tty)
        return;
    puts("MyTeams v0.1.0");
    puts("Type '/login \"username\"', or '/help' for more information.\n");
    fputs(">>> ", stdout);
    fflush(stdout);
}

static void init_client_select(client_t *client)
{
    FD_ZERO(&client->fds_in);
    FD_ZERO(&client->fds_out);
    FD_SET(STDIN_FILENO, &client->fds_in);
    FD_SET(client->sock_fd, &client->fds_in);
    if (client->out_buf.len > 0)
        FD_SET(client->sock_fd, &client->fds_out);
}

int run_client(client_t *client)
{
    int nfds = MY_MAX(STDIN_FILENO, client->sock_fd) + 1;

    greet_client(client);
    while (true) {
        init_client_select(client);
        if (select(nfds, &client->fds_in, &client->fds_out, NULL, NULL) < 0)
            return 84;
        if (handle_client_select(client) == false)
            break;
        if (handle_server_select(client) == false)
            return 0;
    }
    return 0;
}
