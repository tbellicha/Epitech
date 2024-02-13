/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** A pair of UUIDs
*/

#pragma once

#include "hash.h"

#include <uuid/uuid.h>

typedef struct uuid_pair {
    /// The lesser of the two ids.
    uuid_t id_a;
    /// The greater of the two ids.
    uuid_t id_b;
} uuid_pair_t;

/// Initializes the given id pair by placing the lesser of the two ids in
/// front of the pair, and the other in the back.
///
/// @param[out] pair The pair to initialize, may not be NULL.
/// @param id_a The first id.
/// @param id_a The second id.
void uuid_pair_init(uuid_pair_t *pair, uuid_t id_a, uuid_t id_b);

int uuid_pair_cmp(uuid_pair_t const *a, uuid_pair_t const *b);

void uuid_pair_hash(my_hasher_t *restrict hasher, uuid_pair_t const *pair);
