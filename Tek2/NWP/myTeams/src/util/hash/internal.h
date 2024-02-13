/*
** EPITECH PROJECT, 2022
** MyTeams - LibMy Excerpt sources
** File description:
** Hasher internal functions
*/

#pragma once

#include "hash.h"

#include <stddef.h>

/// Resets the state of a hasher.
void p_my_hasher_reset(p_my_hasher_t *hasher);

/// Loads up to 7 bytes from the given buffer in little endian.
///
/// @param length MUST be lower than 8.
uint64_t p_my_hash_load_from_mem(
    unsigned char const *buf, size_t start, size_t length);

#define P_MY_UNWRAP_STATE(H) \
    &H->state_0, &H->state_1, &H->state_2, &H->state_3

void p_my_siphash13_c_rounds(p_my_hasher_t *hasher);
void p_my_siphash13_d_rounds(p_my_hasher_t *hasher);
