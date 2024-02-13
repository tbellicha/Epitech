/*
** EPITECH PROJECT, 2022
** Project
** File description:
** use
*/

#include "client.h"
#include "protocol.h"
#include "error_messages.h"

#include <stdio.h>
#include <string.h>
#include <sys/types.h>

static void command_use_send(
    client_t *client, size_t count, uuid_t ids[count])
{
    my_cbuffer_push_back_uleb128_32(&client->out_buf, C2S_SET_CONTEXT);
    my_cbuffer_push_back_uleb128_32(&client->out_buf, sizeof(uuid_t) * count);
    for (size_t i = 0; i < count; ++i)
        my_cbuffer_push_back(&client->out_buf, ids[i], sizeof(uuid_t));
}

void command_use(client_t *client, char *params)
{
    uuid_t ids[3];
    ssize_t length = 0;
    size_t count = 0;
    char const *end = params + strlen(params);

    while (end - params > 0) {
        length = check_uuid(params, "Invalid uuid format.");
        if (length == -1 || count > 2)
            return;
        uuid_parse(&params[1], ids[count]);
        ++count;
        params += length + 3;
    }
    command_use_send(client, count, ids);
}

void print_helper_use(void)
{
    fputs("/use ?\"team_uuid\" ?\"channel_uuid\" ?\"thread_uuid\": ", stdout);
    fputs("Use a specify context team/channel/thread\n", stdout);
}
