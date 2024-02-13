/*
** EPITECH PROJECT, 2022
** Project
** File description:
** logout
*/

#include "client.h"
#include "commands.h"
#include "protocol.h"

void command_logout(client_t *client, char *params)
{
    (void)params;
    my_cbuffer_push_back_uleb128_32(&client->out_buf, C2S_LOGOUT);
    my_cbuffer_push_back_uleb128_32(&client->out_buf, 0);
}

void print_helper_logout(void)
{
    puts("/logout: Logout from the server");
}
