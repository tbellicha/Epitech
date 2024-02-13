/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** channel
*/

#pragma once

#include "item.h"
#include "protocol.h"
#include "thread.h"

#include <sys/queue.h>

struct team;

/// Structure used to define a channel in a team.
typedef struct channel {
    /// Common item header.
    item_t header;
    /// The parent team.
    struct team *team;
    /// The channel's thread list.
    thread_list_t threads;
    LIST_ENTRY(channel) channels;
    /// The channel's name.
    char name[MAX_NAME_LENGTH + 1];
    /// The channel's description.
    char desc[MAX_DESCRIPTION_LENGTH + 1];
} channel_t;

LIST_HEAD(channel_list, channel);
/// A doubly-linked list of team channels.
typedef struct channel_list channel_list_t;
