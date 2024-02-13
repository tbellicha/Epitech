/*
** EPITECH PROJECT, 2022
** MyTeams - LibMy Excerpt
** File description:
** Random Utilities
*/

#pragma once

#include <stddef.h>
#include <stdint.h>

/// Computes the absolute value of @c x.
///
/// @note
/// Due to MY_ABS, being a macro the @c x expression will be evaluated twice.
///
/// @param x The source number.
///
/// @returns The absolute value of @c x.
/// @since 0.1.0
#define MY_ABS(x) ((x) < 0 ? -(x) : (x))

/// Compares and returns the maximum of two values.
///
/// @param a
/// @param b
///
/// @returns The biggest value, or the second argument if equal.
/// @since 0.1.0
#define MY_MAX(a, b) ((a) > (b) ? (a) : (b))

/// Compares and returns the minimum of two values.
///
/// @param a
/// @param b
///
/// @returns The smallest value, or the first argument if equal.
/// @since 0.1.0
#define MY_MIN(a, b) ((b) < (a) ? (b) : (a))

/// Force casts to given pointer to the type @c t.
///
/// @note This can cause undefined behaviour if the output
///       type is not compatible with the given type!
///
/// @param t   The type of pointer to cast to.
/// @param ptr The pointer to cast.
///
/// @returns The casted pointer.
/// @since 0.2.0
#define MY_CAST(t, ptr) ((t)(void *)ptr)

/// Reverses @c nmemb elements of size @c size in @c mem
///
/// @param mem A pointer to the memory area, must not be @c NULL.
/// @param nmemb The number of elements in @c data.
/// @param size  The size of an individual element of @c data.
///
/// @returns The passed @c mem pointer.
void *my_memrev(void *mem, size_t nmemb, size_t size);

/// Swaps the contents of the given pointers @c a and @c b.
///
/// @param a The first memory location, pointed memory must be at least of
/// @c size bytes.
/// @param b The first memory location, pointed memory must be at least of
/// @c size bytes.
/// @param size The number of bytes to swap.
void my_memswap(void *restrict a, void *restrict b, size_t size);

/// Rotates @c num left by @c shift bits.
///
/// @param num The number the rotate.
/// @param shift The amount of bits to rotate.
///
/// @returns The rotated number.
/// @since 0.2.0
static inline uint64_t my_u64_rotate_left(uint64_t num, unsigned shift)
{
    shift &= 63;
    if (shift == 0)
        return num;
    return (num << shift) | (num >> (64 - shift));
}

/// Rotates @c num right by @c shift bits.
///
/// @param num The number the rotate.
/// @param shift The amount of bits to rotate.
///
/// @returns The rotated number.
/// @since 0.2.0
static inline uint64_t my_u64_rotate_right(uint64_t num, unsigned shift)
{
    shift &= 63;
    if (shift == 0)
        return num;
    return (num >> shift) | (num << (64 - shift));
}
