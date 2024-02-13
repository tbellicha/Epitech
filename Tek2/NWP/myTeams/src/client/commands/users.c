/*
** EPITECH PROJECT, 2022
** Project
** File description:
** users
*/

#include "client.h"
#include "protocol.h"

#include <stdio.h>

void command_users(client_t *client, char *params)
{
    (void)params;
    my_cbuffer_push_back_uleb128_32(&client->out_buf, C2S_GET_USERS);
    my_cbuffer_push_back_uleb128_32(&client->out_buf, 0);
}

void print_helper_users(void)
{
    puts("/users: Get the list of all users that exist on the domain");
}
