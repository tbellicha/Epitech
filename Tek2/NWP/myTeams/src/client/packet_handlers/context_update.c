/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** context_update
*/

#include "client.h"
#include "protocol.h"
#include "logging_client.h"
#include "server_packet_handlers.h"

#include <stdio.h>

static const char *CONTEXT_NAMES[CONTEXT_COUNT] = {
    [CONTEXT_NONE] = "none",
    [CONTEXT_TEAM] = "team",
    [CONTEXT_CHANNEL] = "channel",
    [CONTEXT_THREAD] = "thread",
};

server_packet_result_t s2c_handle_context_update_packet(
    client_t *client, uint32_t len)
{
    char id_str[37] = {0};

    (void)len;
    my_cbuffer_pop_front_uleb128_32(&client->in_buf, &client->context_type);
    my_cbuffer_pop_front(&client->in_buf, &client->context, sizeof(uuid_t));
    uuid_unparse(client->context, id_str);
    printf("Set context to %s (%.8s)\n", CONTEXT_NAMES[client->context_type],
        id_str);
    return PRESULT_OK;
}
