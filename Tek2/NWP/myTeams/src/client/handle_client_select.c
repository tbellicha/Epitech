/*
** EPITECH PROJECT, 2022
** Project
** File description:
** handle_client_select
*/

#include "client.h"
#include "commands/commands.h"
#include "util.h"
#include "client_struct.h"
#include "packet_handlers/server_packet_handlers.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

char *trim_string(char *str)
{
    char *new_str = str;
    int i = 0;
    int x = 0;
    bool in_quotes = false;

    while (str[i]) {
        if (!in_quotes && isspace(str[i]))
            new_str[x++] = ' ';
        while (!in_quotes && isspace(str[i]))
            i++;
        new_str[x++] = str[i];
        if (str[i] == '"')
            in_quotes = !in_quotes;
        i++;
    }
    new_str[x] = '\0';
    return new_str;
}

static ssize_t get_input(char **buff, size_t *buffsize)
{
    ssize_t rd = getline(buff, buffsize, stdin);

    if (rd == -1)
        return rd;
    (*buff)[rd - 1] = '\0';
    *buff = trim_string(*buff);
    return rd;
}

static void show_prompt(client_t const *client)
{
    if (client->tty) {
        fputs(">>> ", stdout);
        fflush(stdout);
    }
}

bool handle_client_select(client_t *client)
{
    char *buff = NULL;
    size_t buffsize = 0;

    if (FD_ISSET(STDIN_FILENO, &client->fds_in)) {
        if (get_input(&buff, &buffsize) == -1) {
            free(buff);
            return false;
        }
        if (buff != NULL)
            handle_command(client, buff);
        show_prompt(client);
    }
    if (FD_ISSET(client->sock_fd, &client->fds_out))
        send_packet(client);
    return true;
}
