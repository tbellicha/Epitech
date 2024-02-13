/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** S2C_MESSAGE_LIST
*/

#include "items/message.h"
#include "leb128.h"
#include "peer.h"
#include "server.h"
#include "util.h"
#include "hash_map.h"

#include <string.h>
#include <uuid/uuid.h>

static const size_t MAX_MESSAGE_LENGTH =
    sizeof(uuid_t) + 10 + 2 + MAX_BODY_LENGTH;
static const size_t MAX_MESSAGE_TMP_BUFFER =
    PEER_BUFFER_SIZE - MAX_MESSAGE_LENGTH;

static uint32_t reply_message_list_write(
    message_list_t *messages, char *buf, uint32_t *count)
{
    uint32_t offset = 0;
    message_t *message = messages ? LIST_FIRST(messages) : NULL;
    size_t message_length;

    while (message && offset < MAX_MESSAGE_TMP_BUFFER) {
        memcpy(buf + offset, message->author, sizeof(uuid_t));
        offset += sizeof(uuid_t);
        offset += uleb128_encode_64(buf + offset, message->timestamp);
        message_length = strlen(message->body);
        offset += uleb128_encode_32(buf + offset, message_length);
        memcpy(buf + offset, message->body, message_length);
        offset += message_length;
        message = LIST_NEXT(message, messages);
        ++(*count);
    }
    return offset;
}

void reply_message_list(peer_t *peer, uuid_t recipient)
{
    message_list_t *messages =
        server_find_messages_list(peer->server, peer->user->id, recipient);
    uint32_t count = 0;
    uint32_t msgs_size =
        reply_message_list_write(messages, peer->tmp_buffer, &count);
    uint32_t count_size = uleb128_size_32(count);

    my_cbuffer_push_back_uleb128_32(&peer->out_buf, S2C_MESSAGE_LIST);
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, count_size + msgs_size);
    my_cbuffer_push_back_uleb128_32(&peer->out_buf, count);
    my_cbuffer_push_back(&peer->out_buf, peer->tmp_buffer, msgs_size);
}
