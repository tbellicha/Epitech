/*
** EPITECH PROJECT, 2021
** MyTeams - LibMy Excerpt
** File description:
** Rounds for the SipHash 1-3 algorithm
*/

#include "hash.h"
#include "hash/internal.h"
#include "util.h"

static void my_sip_compress(
    uint64_t *s0, uint64_t *s1, uint64_t *s2, uint64_t *s3)
{
    *s0 += *s1;
    *s1 = my_u64_rotate_left(*s1, 13);
    *s1 ^= *s0;
    *s0 = my_u64_rotate_left(*s0, 32);
    *s2 += *s3;
    *s3 = my_u64_rotate_left(*s3, 16);
    *s3 ^= *s2;
    *s0 += *s3;
    *s3 = my_u64_rotate_left(*s3, 21);
    *s3 ^= *s0;
    *s2 += *s1;
    *s1 = my_u64_rotate_left(*s1, 17);
    *s1 ^= *s2;
    *s2 = my_u64_rotate_left(*s2, 32);
}

void p_my_siphash13_c_rounds(p_my_hasher_t *hasher)
{
    my_sip_compress(P_MY_UNWRAP_STATE(hasher));
}

void p_my_siphash13_d_rounds(p_my_hasher_t *hasher)
{
    my_sip_compress(P_MY_UNWRAP_STATE(hasher));
    my_sip_compress(P_MY_UNWRAP_STATE(hasher));
    my_sip_compress(P_MY_UNWRAP_STATE(hasher));
}
