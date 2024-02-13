/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** item
*/

#pragma once

#include <time.h>
#include <uuid/uuid.h>

/// Structure used to define the header of other data structures.
typedef struct item {
    /// The item's id.
    uuid_t id;
    /// The item's id as a nul-terminated string.
    char id_str[37];
    /// The thread's creator.
    uuid_t creator;
    /// The thread's creator as a nul-terminated string.
    char creator_str[37];
    /// The thread's timestamp.
    time_t timestamp;
} item_t;
