/*
** EPITECH PROJECT, 2022
** MyTeams: server
** File description:
** The main entrypoint of the server
*/

#include "server.h"

#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int show_help(char const *name)
{
    printf("USAGE: %s port\n\n", name);
    puts("\tport\tis the port number on the server socket listens");
    return 0;
}

static bool parse_args(int ac, char *av[], uint16_t *port)
{
    char *port_str;
    long parsed_port;

    if (ac == 2 && (!strcmp(av[1], "-help") || !strcmp(av[1], "-h")))
        exit(show_help(av[0]));
    if (ac != 2) {
        printf("%s: expected 1 argument, got %d\n", av[0], ac - 1);
        return false;
    }
    parsed_port = strtol(av[1], &port_str, 10);
    if (*port_str != '\0' || parsed_port < 0 || parsed_port > UINT16_MAX) {
        printf("%s: port number must be a number between 0 and %d\n", av[0],
            UINT16_MAX);
        return false;
    }
    *port = (uint16_t)parsed_port;
    return true;
}

int main(int ac, char *av[])
{
    uint16_t port;
    server_t server;

    if (!parse_args(ac, av, &port))
        return 84;
    if (!server_init(&server, port)) {
        printf("%s: %s\n", av[0], strerror(errno));
        return 84;
    }
    server_start(&server);
    server_destroy(&server);
    return 0;
}
