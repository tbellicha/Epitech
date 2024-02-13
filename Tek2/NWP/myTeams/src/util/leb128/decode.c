/*
** EPITECH PROJECT, 2022
** MyTeams - Utilities
** File description:
** LEB128 decoding
*/

#include "endian.h"

#include <stddef.h>
#include <stdint.h>

#include <unistd.h>

size_t uleb128_decode_32(
    void const *restrict input, uint32_t *restrict output)
{
    uint32_t result = 0;
    uint32_t shift = 0;
    uint8_t byte;
    uint8_t const *i = (uint8_t const *)input;

    for (;;) {
        byte = *(i++);
        result |= (byte & 0x7f) << shift;
        if ((byte & 0x80) == 0)
            break;
        shift += 7;
    }
    *output = uint32_to_le(result);
    return (size_t)(i - (uint8_t const *)input);
}

size_t uleb128_decode_64(
    void const *restrict input, uint64_t *restrict output)
{
    uint32_t result = 0;
    uint32_t shift = 0;
    uint8_t byte;
    uint8_t const *i = (uint8_t const *)input;

    for (;;) {
        byte = *(i++);
        result |= (byte & 0x7f) << shift;
        if ((byte & 0x80) == 0)
            break;
        shift += 7;
    }
    *output = uint64_to_le(result);
    return (size_t)(i - (uint8_t const *)input);
}
