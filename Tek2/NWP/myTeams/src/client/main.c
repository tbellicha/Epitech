/*
** EPITECH PROJECT, 2022
** MyTeams: client
** File description:
** The main entrypoint of the client
*/

#include "client.h"

#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const **argv)
{
    enum args_handling args = check_args(argc, argv);
    client_t client = {0};
    int res = 0;

    fcntl(STDIN_FILENO, F_SETFL, fcntl(0, F_GETFL, 0) | O_NONBLOCK);
    switch (args) {
        case ARGS_HELPER: return ARGS_HELPER;
        case ARGS_INVALID: return 84;
        default: break;
    }
    if (!connect_client(argv[1], argv[2], &client))
        return 84;
    res = run_client(&client);
    close(client.sock_fd);
    return res;
}
