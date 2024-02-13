/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** MyTeams unique user
*/

#pragma once

#include "protocol.h"

#include <sys/queue.h>
#include <time.h>
#include <uuid/uuid.h>

struct peer;

/// User -> Peer mapping.
typedef struct user_session {
    struct peer *peer;
    LIST_ENTRY(user_session) sessions;
} user_session_t;

LIST_HEAD(user_session_list, user_session);

/// A doubly-linked list of server user sessions.
typedef struct user_session_list user_session_list_t;

typedef struct user {
    /// The user's UUID.
    uuid_t id;
    /// The user's UUID, in nul-terminated string form.
    char id_str[37];
    /// The list of all active peers that are using this user.
    user_session_list_t sessions;
    /// The user's creation date.
    time_t timestamp;
    /// Server users list.
    LIST_ENTRY(user) users;
    char name[MAX_NAME_LENGTH + 1];
} user_t;

LIST_HEAD(user_list, user);

/// A doubly-linked list of server users.
typedef struct user_list user_list_t;
