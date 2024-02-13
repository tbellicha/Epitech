/*
** EPITECH PROJECT, 2022
** Project
** File description:
** list
*/

#include "cbuffer.h"
#include "client.h"
#include "leb128.h"
#include "protocol.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static void send_list_packet(c2s_packet_id_t id, client_t *client)
{
    my_cbuffer_push_back_uleb128_32(&client->out_buf, id);
    if (id == C2S_GET_TEAMS)
        my_cbuffer_push_back_uleb128_32(&client->out_buf, 0);
    else {
        my_cbuffer_push_back_uleb128_32(&client->out_buf, sizeof(uuid_t));
        my_cbuffer_push_back(
            &client->out_buf, client->context, sizeof(uuid_t));
    }
}

void command_list(client_t *client, char *params)
{
    (void)params;
    context_type_t type = client->context_type;

    switch (type) {
        case CONTEXT_NONE: send_list_packet(C2S_GET_TEAMS, client); break;
        case CONTEXT_TEAM: send_list_packet(C2S_GET_CHANNELS, client); break;
        case CONTEXT_CHANNEL:
            send_list_packet(C2S_GET_THREADS, client);
            break;
        case CONTEXT_THREAD:
        default: send_list_packet(C2S_GET_COMMENTS, client); break;
    }
}

void print_helper_list(void)
{
    puts("When the context is not defined (/use):");
    puts("\t/list: list all existing teams");
    puts("When team_uuid is defined (/use \"team_uuid\"):");
    puts("\t/list: list all existing channels");
    fputs("When team_uuid and channel_uuid are defined ", stdout);
    fputs("(/use \"team_uuid\" \"channel_uuid\"):\n", stdout);
    puts("\t/list: list all existing threads");
    fputs(
        "When team_uuid, channel_uuid and thread_uuid are defined ", stdout);
    fputs("(/use \"team_uuid\" \"channel_uuid\" \"thread_uuid\"):\n", stdout);
    puts("\t/list: list all existing replies");
}
