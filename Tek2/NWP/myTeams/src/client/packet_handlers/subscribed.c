/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** S2C_SUBSCRIBED
*/

#include "logging_client.h"
#include "server_packet_handlers.h"

server_packet_result_t s2c_handle_subscribed_packet(
    client_t *client, uint32_t len)
{
    uuid_t team_id;
    char team_id_str[37] = {0};
    char user_id_str[37] = {0};

    (void)len;
    my_cbuffer_pop_front(&client->in_buf, team_id, sizeof(uuid_t));
    uuid_unparse(team_id, team_id_str);
    uuid_unparse(client->uuid, user_id_str);
    client_print_subscribed(user_id_str, team_id_str);
    return PRESULT_OK;
}
