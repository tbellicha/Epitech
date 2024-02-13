/*
** EPITECH PROJECT, 2022
** Myteams
** File description:
** find_messages_list
*/

#include "items/message.h"
#include "peer.h"
#include "server.h"
#include "hash_map.h"
#include "uuid_util.h"

#include <string.h>
#include <uuid/uuid.h>

/// Returns the list of messages between the users @b a and @b b.
///
/// @returns The message list, or @c NULL if it does not exist.
message_list_t *server_find_messages_list(
    server_t *server, uuid_t a, uuid_t b)
{
    uuid_pair_t key;

    uuid_pair_init(&key, a, b);
    return (message_list_t *)my_hash_map_get(&server->messages, &key);
}
