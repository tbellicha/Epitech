/*
** EPITECH PROJECT, 2022
** Project
** File description:
** info
*/

#include "cbuffer.h"
#include "client.h"
#include "protocol.h"

#include <stdio.h>
#include <uuid/uuid.h>

static void send_info_packet(c2s_packet_id_t id, client_t *client)
{
    my_cbuffer_push_back_uleb128_32(&client->out_buf, id);
    my_cbuffer_push_back_uleb128_32(&client->out_buf, sizeof(uuid_t));
    if (id == C2S_GET_USER_INFO)
        my_cbuffer_push_back(&client->out_buf, client->uuid, sizeof(uuid_t));
    else
        my_cbuffer_push_back(
            &client->out_buf, client->context, sizeof(uuid_t));
}

void command_info(client_t *client, char *params)
{
    (void)params;
    context_type_t type = client->context_type;

    switch (type) {
        case CONTEXT_NONE: send_info_packet(C2S_GET_USER_INFO, client); break;
        case CONTEXT_TEAM: send_info_packet(C2S_GET_TEAM_INFO, client); break;
        case CONTEXT_CHANNEL:
            send_info_packet(C2S_GET_CHANNEL_INFO, client);
            break;
        case CONTEXT_THREAD:
        default: send_info_packet(C2S_GET_THREAD_INFO, client); break;
    }
}

void print_helper_info(void)
{
    puts("When the context is not defined (/use):");
    puts("\t/info: display currently logged user infos");
    puts("When team_uuid is defined (/use \"team_uuid\"):");
    puts("\t/info: display currently selected team infos");
    fputs("When team_uuid and channel_uuid are defined ", stdout);
    fputs("(/use \"team_uuid\" \"channel_uuid\"):\n", stdout);
    puts("\t/info: display currently selected channel infos");
    fputs(
        "When team_uuid, channel_uuid and thread_uuid are defined ", stdout);
    fputs("(/use \"team_uuid\" \"channel_uuid\" \"thread_uuid\"):\n", stdout);
    puts("\t/info: display currently selected thread infos");
}
