/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** messages_map
*/

#include "items/message.h"
#include "hash_map.h"
#include "uuid_util.h"

#include <stdlib.h>

static void server_messages_drop(message_list_t *messages)
{
    message_t *message;
    message_t *next;

    message = LIST_FIRST(messages);
    while (message) {
        next = LIST_NEXT(message, messages);
        free(message);
        message = next;
    }
}

void server_init_messages_map(my_hash_map_t *users)
{
    const my_map_kvtypes_t map_type = {
        .key_size = sizeof(uuid_pair_t),
        .key_align = _Alignof(uuid_t),
        .value_size = sizeof(message_list_t),
        .value_align = _Alignof(message_list_t),
        .compare = (my_map_compare_keys_t)&uuid_pair_cmp,
        .hash = (my_map_hash_key_t)&uuid_pair_hash,
        .key_drop = NULL,
        .value_drop = (my_map_drop_t)&server_messages_drop,
    };
    my_hash_map_init(users, &map_type);
}
