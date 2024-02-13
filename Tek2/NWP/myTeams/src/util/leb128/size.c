/*
** EPITECH PROJECT, 2022
** MyTeams - Utilities
** File description:
** LEB128 encoding size
*/

#include "endian.h"

#include <stddef.h>
#include <stdint.h>

/// bit size to byte size lookup.
static const int ULEB128_SIZES_TABLE[] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2,
    2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 6,
    6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9,
    9, 9, 10};

size_t uleb128_size_32(uint32_t input)
{
    return ULEB128_SIZES_TABLE[input ? 32 - __builtin_clz(input) : 0];
}

size_t uleb128_size_64(uint64_t input)
{
    return ULEB128_SIZES_TABLE[input ? 64 - __builtin_clzll(input) : 0];
}
