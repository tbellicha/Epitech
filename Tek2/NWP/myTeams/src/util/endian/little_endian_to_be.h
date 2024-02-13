/*
** EPITECH PROJECT, 2021
** LibMy - memory module
** File description:
** Endian-related utilities
*/

#pragma once

/// @b NO-OP This function is provided for completeness.
///
/// @param num The integer.
///
/// @returns Always @c num.
/// @since 0.3.11
static inline uint8_t uint8_to_be(uint8_t num)
{
    return num;
}

/// Converts a native-endian 16-bit unsigned integer to (or from) big endian.
///
/// @param num The integer.
///
/// @returns The integer, converted to big endian if neccessary.
/// @since 0.2.0
static inline uint16_t uint16_to_be(uint16_t num)
{
    my_m16_t n = {.num = num};

    return ((my_m16_t){.data = {n.data[1], n.data[0]}}).num;
}

/// Converts a native-endian 32-bit unsigned integer to (or from) big endian.
///
/// @param num The integer.
///
/// @returns The integer, converted to big endian if neccessary.
/// @since 0.2.0
static inline uint32_t uint32_to_be(uint32_t num)
{
    my_m32_t n = {.num = num};

    return ((my_m32_t){.data = {n.data[3], n.data[2], n.data[1], n.data[0]}})
        .num;
}

/// Converts a native-endian 64-bit unsigned integer to (or from) big endian.
///
/// @param num The integer.
///
/// @returns The integer, converted to big endian if neccessary.
/// @since 0.2.0
static inline uint64_t uint64_to_be(uint64_t num)
{
    my_m64_t n = {.num = num};
    my_m64_t res = {.data = {n.data[7], n.data[6], n.data[5], n.data[4],
                        n.data[3], n.data[2], n.data[1], n.data[0]}};

    return res.num;
}
