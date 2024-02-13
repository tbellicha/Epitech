/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Handling Login packet from server
*/

#include "client.h"
#include "protocol.h"
#include "logging_client.h"
#include "server_packet_handlers.h"

#include <stdio.h>
#include <string.h>

server_packet_result_t s2c_handle_login_packet(client_t *client, uint32_t len)
{
    uuid_t id;
    char name[MAX_NAME_LENGTH + 1] = {0};
    char id_str[37] = {0};

    my_cbuffer_pop_front(&client->in_buf, id, sizeof(uuid_t));
    my_cbuffer_pop_front(&client->in_buf, name, len - sizeof(uuid_t));
    uuid_unparse(id, id_str);
    client_event_logged_in(id_str, name);
    if (strcmp(client->name, name) == 0)
        uuid_copy(client->uuid, id);
    return PRESULT_OK;
}
