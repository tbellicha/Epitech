/*
** EPITECH PROJECT, 2022
** Projects
** File description:
** init_client
*/

#include "ftp.h"

client_t* init_client(client_t* client, char *path,
struct sockaddr_in cli)
{
    client->path = strdup(path);
    client->ip = inet_ntoa(cli.sin_addr);
    client->login = LOGIN_NONE;
    dprintf(client->fd, "220 Service ready for new user.\n");
    return (client);
}

void run_client(ftp_t *server, client_t *client)
{
    char buffer[BUFFER_SIZE];

    while (true) {
        read(client->fd, buffer, BUFFER_SIZE);
        handle_command(server, client,
            str_to_word_array(buffer, "\t\r\n "));
        if (client->login == LOGIN_DISC)
            break;
        memset(buffer, 0, sizeof(buffer));
    }
    close(server->server_fd);
    exit(0);
}