/*
** EPITECH PROJECT, 2022
** Myteams
** File description:
** message
*/

#include "items/message.h"
#include "cbuffer.h"
#include "items/user.h"
#include "leb128.h"
#include "peer.h"
#include "protocol.h"
#include "logging_server.h"

#include <string.h>
#include <time.h>
#include <uuid/uuid.h>

void reply_message(peer_t *peer_dst, message_t *item, my_cbuffer_t *out)
{
    time_t timestamp = time(NULL);
    uint32_t timestamp_size = uleb128_size_64(timestamp);
    uint32_t total_size =
        timestamp_size + strlen(item->body) + 2 * sizeof(uuid_t);

    my_cbuffer_push_back_uleb128_32(out, S2C_MESSAGE_CREATED);
    my_cbuffer_push_back_uleb128_32(out, total_size);
    my_cbuffer_push_back_uleb128_64(out, item->timestamp);
    my_cbuffer_push_back(out, item->author, sizeof(uuid_t));
    my_cbuffer_push_back(out, peer_dst->user->id, sizeof(uuid_t));
    my_cbuffer_push_back(out, item->body, strlen(item->body));
}
