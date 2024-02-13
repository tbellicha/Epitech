/*
** EPITECH PROJECT, 2022
** Project
** File description:
** run
*/

#include "client.h"

#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

static bool check_port(const char *port)
{
    char *end_pointer;
    long port_value = strtol(port, &end_pointer, 10);

    if (!port_value || port_value < 1 || port_value > UINT16_MAX) {
        puts("Invalid port value.");
        return false;
    }
    return true;
}

void init_client(client_t *client)
{
    my_cbuffer_init(&client->in_buf, client->raw_in_buf, CLIENT_BUFFER_SIZE);
    my_cbuffer_init(
        &client->out_buf, client->raw_out_buf, CLIENT_BUFFER_SIZE);
    uuid_clear(client->uuid);
    memset(client->name, 0, sizeof(client->name));
    client->tty = !!isatty(STDIN_FILENO);
}

bool connect_client(char const *ip, char const *port, client_t *client)
{
    if (!check_port(port))
        return false;
    client->sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sock_fd == -1) {
        puts("Socket connection failed.");
        return false;
    }
    client->sock_size = sizeof(client->sockaddr);
    memset(&client->sockaddr, 0, client->sock_size);
    client->sockaddr.sin_family = AF_INET;
    client->sockaddr.sin_addr.s_addr = inet_addr(ip);
    client->sockaddr.sin_port = htons(atoi(port));
    if (connect(client->sock_fd, (struct sockaddr *)&client->sockaddr,
            client->sock_size)) {
        printf("Failed to connect to the server: %s.\n", strerror(errno));
        return false;
    }
    init_client(client);
    return true;
}
