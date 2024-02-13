/*
** EPITECH PROJECT, 2022
** Project
** File description:
** channel_list
*/

#include "client.h"
#include "protocol.h"
#include "logging_client.h"
#include "server_packet_handlers.h"

#include <string.h>

static void send_first_part(
    client_t *client, uuid_t id, uint32_t *name_length, char *name)
{
    my_cbuffer_pop_front(&client->in_buf, id, sizeof(uuid_t));
    my_cbuffer_pop_front_uleb128_32(&client->in_buf, name_length);
    my_cbuffer_pop_front(&client->in_buf, name, *name_length);
}

static void send_second_part(
    client_t *client, uint32_t *desc_length, char *desc)
{
    my_cbuffer_pop_front_uleb128_32(&client->in_buf, desc_length);
    my_cbuffer_pop_front(&client->in_buf, desc, *desc_length);
}

server_packet_result_t s2c_handle_channel_list_packet(
    client_t *client, uint32_t len)
{
    uint32_t count;
    uuid_t id;
    char name[MAX_NAME_LENGTH + 1] = {0};
    uint32_t name_length;
    char desc[MAX_DESCRIPTION_LENGTH + 1] = {0};
    uint32_t desc_length;
    char id_str[37] = {0};

    (void)len;
    my_cbuffer_pop_front_uleb128_32(&client->in_buf, &count);
    for (size_t i = 0; i < count; i++) {
        memset(name, 0, sizeof(name));
        memset(desc, 0, sizeof(desc));
        memset(id_str, 0, sizeof(id_str));
        send_first_part(client, id, &name_length, name);
        send_second_part(client, &desc_length, desc);
        uuid_unparse(id, id_str);
        client_team_print_channels(id_str, name, desc);
    }
    return PRESULT_OK;
}
