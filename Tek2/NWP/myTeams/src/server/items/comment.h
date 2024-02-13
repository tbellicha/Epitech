/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** comment
*/

#pragma once

#include "item.h"
#include "protocol.h"

#include <sys/queue.h>

struct thread;

/// Structure used to define a channel in a team.
typedef struct comment {
    /// Common item header.
    item_t header;
    /// The original post.
    struct thread *thread;
    LIST_ENTRY(comment) comments;
    /// The comment's body.
    char body[MAX_BODY_LENGTH + 1];
} comment_t;

LIST_HEAD(comment_list, comment);
/// A doubly-linked list of thread comments.
typedef struct comment_list comment_list_t;
