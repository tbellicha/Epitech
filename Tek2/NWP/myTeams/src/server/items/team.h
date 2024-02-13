/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** team
*/

#pragma once

#include "channel.h"
#include "item.h"
#include "protocol.h"

#include <sys/queue.h>

struct user;

typedef struct team_subscriber {
    struct user *user;
    LIST_ENTRY(team_subscriber) subscribers;
} team_subscriber_t;

LIST_HEAD(team_subscriber_list, team_subscriber);

/// A doubly-linked list of team followers.
typedef struct team_subscriber_list team_subscriber_list_t;

/// Structure used to define a team.
typedef struct team {
    /// Common item header.
    item_t header;
    /// The team's channel list.
    channel_list_t channels;
    /// The list of all users that are subsribed to this team.
    team_subscriber_list_t subscribers;
    LIST_ENTRY(team) teams;
    /// The team's name.
    char name[MAX_NAME_LENGTH + 1];
    /// The team's description.
    char desc[MAX_DESCRIPTION_LENGTH + 1];
} team_t;

LIST_HEAD(team_list, team);
/// A doubly-linked list of teams.
typedef struct team_list team_list_t;
