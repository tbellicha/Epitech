/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Receive message client packet
*/

#include "items/message.h"
#include "leb128.h"
#include "peer.h"
#include "server.h"
#include "logging_server.h"
#include "packet_handlers.h"
#include "packet_reply.h"
#include "uuid_util.h"

#include <stdlib.h>
#include <string.h>

static void fill_message_item(
    message_t *item, uuid_t author_id, char *message)
{
    uuid_copy(item->author, author_id);
    strcpy(item->body, message);
    item->timestamp = time(NULL);
}

static void create_messages_list_if_needed(peer_t *peer, uuid_t id)
{
    message_list_t *messages =
        server_find_messages_list(peer->server, peer->user->id, id);
    message_list_t new_message_list;
    uuid_pair_t key;

    if (messages == NULL) {
        LIST_INIT(&new_message_list);
        uuid_pair_init(&key, peer->user->id, id);
        my_hash_map_insert(&peer->server->messages, &key, &new_message_list);
    }
}

static void handle_message_result(
    peer_t *peer, peer_t *dst_peer, message_t *item)
{
    reply_message(dst_peer, item, &peer->out_buf);
    reply_message(dst_peer, item, &dst_peer->out_buf);
    peer_log(
        peer, "Sent '%s' to user (%.8s)", item->body, dst_peer->user->id_str);
    server_event_private_message_sended(
        peer->user->id_str, dst_peer->user->id_str, item->body);
}

static packet_result_t handle_message_reply(
    peer_t *peer, uuid_t id, char *message)
{
    peer_t *dst_peer = server_find_peer(peer->server, id);
    message_t *item;

    if (!dst_peer) {
        reply_unknown_item(peer, id, REPLY_UNKNOWN_USER);
        return PRESULT_OK;
    }
    item = calloc(sizeof(*item), 1);
    if (!item)
        return PRESULT_INTERNAL_ERROR;
    fill_message_item(item, peer->user->id, message);
    create_messages_list_if_needed(peer, id);
    LIST_INSERT_HEAD(
        server_find_messages_list(peer->server, peer->user->id, id), item,
        messages);
    handle_message_result(peer, dst_peer, item);
    return PRESULT_OK;
}

packet_result_t handle_message_packet(peer_t *peer, size_t length)
{
    char message[MAX_BODY_LENGTH + 1] = {0};
    uuid_t id;

    if (!peer_check_logged_in(peer, length))
        return PRESULT_OK;
    if (length == 0 || length > MAX_BODY_LENGTH + sizeof(uuid_t)) {
        reply_error(
            peer, REPLY_INVALID_LENGTH, "invalid body length", length);
        return PRESULT_OK;
    }
    my_cbuffer_pop_front(&peer->in_buf, &id, 16);
    my_cbuffer_pop_front(&peer->in_buf, message, length);
    return handle_message_reply(peer, id, message);
}
