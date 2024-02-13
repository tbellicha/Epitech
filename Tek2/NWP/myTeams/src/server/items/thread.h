/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** thread
*/

#pragma once

#include "comment.h"
#include "item.h"
#include "protocol.h"

#include <sys/queue.h>

struct channel;

/// Structure used to define a thread in a channel.
typedef struct thread {
    /// Common item header.
    item_t header;
    /// The parent comment.
    struct channel *channel;
    /// The list of comments in this thread.
    comment_list_t comments;
    LIST_ENTRY(thread) threads;
    /// The thread's title.
    char title[MAX_NAME_LENGTH + 1];
    /// The thread's message.
    char body[MAX_BODY_LENGTH + 1];
} thread_t;

LIST_HEAD(thread_list, thread);
/// A doubly-linked list of threads.
typedef struct thread_list thread_list_t;
