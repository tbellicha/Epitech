/*
** EPITECH PROJECT, 2022
** Projects
** File description:
** port
*/

#include "ftp.h"

bool check_port(const char* port)
{
    int i = 0;

    while (port[i]) {
        if (port[i] < '0' || port[i] > '9')
            return false;
        i++;
    }
    if (atoi(port) < 1 || atoi(port) > 65535)
        return false;
    return true;
}

void exec_port(client_t *client, char **params)
{
    struct protoent *pr_e = NULL;

    if (client->login == LOGIN_CNCT) {
        if (params == NULL || params[0] == NULL) {
            dprintf(client->fd,
                "501 Syntax error in parameters or arguments.\n");
            return;
        }
        for (int i = 0; params[i]; i++) {
            if (strspn(params[i], "0123456789") != strlen(params[i])) {
                dprintf(client->fd,
                    "501 Syntax error in parameters or arguments.\n");
                return;
            }
        }
        dprintf(client->fd, "227 Entering Passive Mode (h1,h2,h3,h4,p1,p2).\n");
    } else {
        dprintf(client->fd, "530 Not logged in.\n");
    }
}
