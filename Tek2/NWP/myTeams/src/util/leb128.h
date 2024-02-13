/*
** EPITECH PROJECT, 2022
** MyTeams - Utilities
** File description:
** LEB128 encoding
*/

#pragma once

#include <stddef.h>
#include <stdint.h>

/// Encodes the given 32-bit unsigned integer to ULEB-128 into the given
/// buffer.
///
/// @param[out] output Where the encoded int will be written, MUST have a
/// capacity of AT LEAST 5 bytes.
/// @param input The int to encode.
///
/// @returns The number of bytes encoded always between 1 and 5 (inclusive).
size_t uleb128_encode_32(void *output, uint32_t input);

/// Encodes the given 64-bit unsigned integer to ULEB-128 into the given
/// buffer.
///
/// @param[out] output Where the encoded int will be written, MUST have a
/// capacity of AT LEAST 10 bytes.
/// @param input The int to encode.
///
/// @returns The number of bytes encoded always between 1 and 5 (inclusive).
size_t uleb128_encode_64(void *output, uint64_t input);

/// Decodes a 32-bit ULEB-128 encoded integer from @b input into the location
/// of @b output.
///
/// @param input The location of an ULEB-128 encoded int.
/// @param[out] output Where the decoded integer is stored.
///
/// @returns The size of the encoded integer, between 1 and 5 (inclusive).
size_t uleb128_decode_32(
    void const *restrict input, uint32_t *restrict output);

/// Decodes a 64-bit ULEB-128 encoded integer from @b input into the location
/// of @b output.
///
/// @param input The location of an ULEB-128 encoded int.
/// @param[out] output Where the decoded integer is stored.
///
/// @returns The size of the encoded integer, between 1 and 5 (inclusive).
size_t uleb128_decode_64(
    void const *restrict input, uint64_t *restrict output);

/// @returns The number of bytes required to encode the 32-bit @b input.
size_t uleb128_size_32(uint32_t input);

/// @returns The number of bytes required to encode the 64-bit @b input.
size_t uleb128_size_64(uint64_t input);
