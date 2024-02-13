/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Direct message
*/

#pragma once

#include "protocol.h"

#include <sys/queue.h>
#include <time.h>
#include <uuid/uuid.h>

/// Structure used to define a message sent to an other user.
typedef struct message {
    /// The message's timestamp.
    time_t timestamp;
    /// The message's author.
    uuid_t author;
    LIST_ENTRY(message) messages;
    /// The message's id.
    char body[MAX_BODY_LENGTH + 1];
} message_t;

LIST_HEAD(message_list, message);

/// A doubly-linked list of direct messages.
typedef struct message_list message_list_t;
