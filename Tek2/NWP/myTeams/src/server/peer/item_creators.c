/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** item_creators
*/

#include "peer.h"
#include "protocol.h"

peer_item_creator_t PEER_ITEM_CREATORS[CONTEXT_COUNT] = {
    [CONTEXT_NONE] = &peer_create_team,
    [CONTEXT_TEAM] = &peer_create_channel,
    [CONTEXT_CHANNEL] = &peer_create_thread,
    [CONTEXT_THREAD] = &peer_create_comment,
};
