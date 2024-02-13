/*
** EPITECH PROJECT, 2022
** Projects
** File description:
** commands\n
*/

#include "ftp.h"

void exec_noop(client_t *client, char **params)
{
    if (client->login != LOGIN_CNCT) {
        dprintf(client->fd, "530 Not logged in.\n");
    } else {
        dprintf(client->fd, "200 NOOP okay.\n");
    }
}

void exec_retr(client_t *client, char **params)
{
    if (client->login != LOGIN_CNCT) {
        dprintf(client->fd, "530 Not logged in.\n");
        return;
    }
}

void exec_stor(client_t *client, char **params)
{
    printf("exec_stor\n");
}

void exec_list(client_t *client, char **params)
{
    printf("exec_list\n");
}
