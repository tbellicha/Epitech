/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** login
*/

#include "client.h"
#include "commands.h"
#include "protocol.h"

#include <string.h>
#include <unistd.h>

void command_login(client_t *client, char *params)
{
    ssize_t len =
        parse_string(params, "Can't login with an empty user name.");

    if (len <= 0)
        return;
    my_cbuffer_push_back_uleb128_32(&client->out_buf, C2S_LOGIN);
    my_cbuffer_push_back_uleb128_32(&client->out_buf, len);
    my_cbuffer_push_back(&client->out_buf, &params[1], len);
    memset(client->name, 0, sizeof(client->name));
    strncpy(client->name, &params[1], len);
}

void print_helper_login(void)
{
    puts("/login \"user_name\": Login to the server");
}
