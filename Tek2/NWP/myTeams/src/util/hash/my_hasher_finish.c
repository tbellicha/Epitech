/*
** EPITECH PROJECT, 2021
** MyTeams - LibMy Excerpt
** File description:
** Finishes the hash process
*/

#include "hash.h"
#include "hash/internal.h"

uint64_t my_hasher_finish(my_hasher_t const *hasher_outer)
{
    p_my_hasher_t hasher = hasher_outer->inner;
    uint64_t data = ((((uint64_t)hasher.length) & 0xff) << 56) | hasher.tail;

    hasher.state_3 ^= data;
    p_my_siphash13_c_rounds(&hasher);
    hasher.state_0 ^= data;
    hasher.state_2 ^= 0xff;
    p_my_siphash13_d_rounds(&hasher);
    return hasher.state_0 ^ hasher.state_1 ^ hasher.state_2 ^ hasher.state_3;
}
