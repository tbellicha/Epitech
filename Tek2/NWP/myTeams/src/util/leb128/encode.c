/*
** EPITECH PROJECT, 2022
** MyTeams - Utilities
** File description:
** LEB128 encoding
*/

#include "endian.h"

#include <stddef.h>
#include <stdint.h>

size_t uleb128_encode_32(void *output, uint32_t input)
{
    uint8_t byte;
    uint8_t *o = (uint8_t *)output;

    input = uint32_to_le(input);
    do {
        byte = input & 0x7f;
        input >>= 7;
        if (input != 0)
            byte |= 0x80;
        *(o++) = byte;
    } while (input != 0);
    return (size_t)(o - (uint8_t *)output);
}

size_t uleb128_encode_64(void *output, uint64_t input)
{
    uint8_t byte;
    uint8_t *o = (uint8_t *)output;

    input = uint64_to_le(input);
    do {
        byte = input & 0x7f;
        input >>= 7;
        if (input != 0)
            byte |= 0x80;
        *(o++) = byte;
    } while (input != 0);
    return (size_t)(o - (uint8_t *)output);
}
