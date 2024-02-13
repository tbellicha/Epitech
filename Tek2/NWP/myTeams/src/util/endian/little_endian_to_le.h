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
static inline uint8_t uint8_to_le(uint8_t num)
{
    return num;
}

/// Converts a native-endian 16-bit unsigned integer to (or from) little
/// endian.
///
/// @param num The integer.
///
/// @returns The integer, converted to little endian if neccessary.
/// @since 0.2.0
static inline uint16_t uint16_to_le(uint16_t num)
{
    return num;
}

/// Converts a native-endian 32-bit unsigned integer to (or from) little
/// endian.
///
/// @param num The integer.
///
/// @returns The integer, converted to little endian if neccessary.
/// @since 0.2.0
static inline uint32_t uint32_to_le(uint32_t num)
{
    return num;
}

/// Converts a native-endian 64-bit unsigned integer to (or from) little
/// endian.
///
/// @param num The integer.
///
/// @returns The integer, converted to little endian if neccessary.
/// @since 0.2.0
static inline uint64_t uint64_to_le(uint64_t num)
{
    return num;
}
