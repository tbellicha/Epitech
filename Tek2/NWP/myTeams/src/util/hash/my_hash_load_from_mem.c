/*
** EPITECH PROJECT, 2021
** MyTeams - LibMy Excerpt
** File description:
** Loads up to 7 bytes from the given buffer
*/

#include "endian.h"
#include "hash.h"
#include "util.h"

static uint64_t hash_load_u16(unsigned char const *buf, size_t start)
{
    my_m16_t out = {0};

    out.data[0] = buf[start];
    out.data[1] = buf[start + 1];
    return (uint64_t)uint16_to_le(out.num);
}

static uint64_t hash_load_u32(unsigned char const *buf, size_t start)
{
    my_m32_t out = {0};

    out.data[0] = buf[start];
    out.data[1] = buf[start + 1];
    out.data[2] = buf[start + 2];
    out.data[3] = buf[start + 3];
    return (uint64_t)uint32_to_le(out.num);
}

uint64_t p_my_hash_load_from_mem(
    unsigned char const *buf, size_t start, size_t length)
{
    size_t i = 0;
    uint64_t out = 0;

    if (i + 3 < length) {
        out = hash_load_u32(buf, start);
        i += 4;
    }
    if (i + 1 < length) {
        out |= hash_load_u16(buf, start + i) << (i * 8);
        i += 2;
    }
    if (i < length) {
        out |= ((uint64_t)buf[start + i]) << (i * 8);
    }
    return out;
}
