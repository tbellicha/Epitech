/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** init_item_header
*/

#include "items/item.h"
#include "items/user.h"
#include "peer.h"

#include <string.h>
#include <uuid/uuid.h>

void peer_init_item_header(peer_t *peer, struct item *header)
{
    uuid_generate(header->id);
    memset(header->id_str, 0, sizeof(header->id_str));
    uuid_unparse(header->id, header->id_str);
    uuid_copy(header->creator, peer->user->id);
    uuid_unparse(header->creator, header->creator_str);
    header->timestamp = time(NULL);
}
