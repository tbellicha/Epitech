/*
** EPITECH PROJECT, 2022
** MyTeams - LibMy Excerpt
** File description:
** Defines the my_cbuffer_t type as well as operations for it
*/

/// @file
///
/// Defines the circular buffer type @ref my_vec_t and ways to operate on it.

#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

/// A circular buffer
typedef struct {
    /// The inner memory.
    void *data;
    /// The number of bytes that @c bytes can hold.
    size_t cap;
    /// The distance between @c head and @c tail.
    /// The buffer is empty if <tt>head == tail</tt> and <tt>len == 0</tt>.
    size_t len;
    /// Points to the first element that could be read.
    size_t tail;
    /// Points to where data should be read.
    size_t head;
} my_cbuffer_t;

/// Initializes the passed circular buffer.
///
/// @param[out] buf The buffer to initialize.
/// @param data     The data pointer that the buffer will store.
/// @param capacity The maximum size (in bytes) of @c data.
void my_cbuffer_init(my_cbuffer_t *buf, void *data, size_t capacity);

/// Checks whether the passed circular buffer is contiguous.
///
/// @param buf The buffer.
///
/// @returns 1 is the buffer is contiguous, 0 otherwise.
static inline int my_cbuffer_is_contiguous(my_cbuffer_t const *buf)
{
    return buf->tail < buf->head || buf->len == 0;
}

/// Returns the first part of the passed circular buffer.
///
/// @param buf  The buffer.
/// @param size Where the size of the part will be stored.
///             If @c buf is contiguous, then @c size will equal
///             <tt>buf->size</tt>.
///             Can be @c NULL.
///
/// @returns A pointer to the start of the first part of @c buf.
void *my_cbuffer_get_first_part(my_cbuffer_t const *buf, size_t *size);

/// Returns the second part of the passed circular buffer.
///
/// @param buf  The buffer.
/// @param size Where the size of the part will be stored.
///             If @c buf is contiguous, then @c size will be set to 0.
///             Can be @c NULL.
///
/// @returns A pointer to the start of the second part of @c buf.
void *my_cbuffer_get_second_part(my_cbuffer_t const *buf, size_t *size);

/// Returns the parts of the passed circular buffer.
/// If the buffer is contiguous, the second part pointer will be set
/// to the end of the buffer and the size set to 0.
///
/// @param      buf   The buffer.
/// @param[out] ptrs  Where the two parts starting pointers will be stored.
/// @param[out] sizes Where the sizes of the two parts will be stored.
static inline void my_cbuffer_get_parts(
    my_cbuffer_t const *buf, void *ptrs[2], size_t sizes[2])
{
    ptrs[0] = my_cbuffer_get_first_part(buf, sizes);
    ptrs[1] = my_cbuffer_get_second_part(buf, sizes + 1);
}

/// Reads @c size bytes from the circular buffer @c buf starting from
/// <tt>buf->tail</tt>.
///
/// @param buf      The buffer, this function assumes that
///                 <tt>buf->data</tt> is a valid memory location.
/// @param[out] dst Where the read data will be stored, must be valid.
/// @param size     The number of bytes to read from the buffer.
///                 Must be lower or equal to <tt>buf->len</tt>.
///
/// @returns A pointer to @c dst.
void *my_cbuffer_read_front(my_cbuffer_t const *buf, void *dst, size_t size);

/// Reads @c size bytes from the circular buffer @c buf starting from
/// <tt>buf->tail</tt> and writes them to the given file descriptor.
///
/// @param buf      The buffer, this function assumes that
///                 <tt>buf->data</tt> is a valid memory location.
/// @param fd       The output file descriptor.
///
/// @returns The number of bytes written to @c fd, or -1 on error.
ssize_t my_cbuffer_read_front_to(my_cbuffer_t const *buf, int fd);

/// Reads @c size bytes from the back of the circular buffer @c buf.
///
/// @param buf      The buffer, this function assumes that
///                 <tt>buf->data</tt> is a valid memory location.
/// @param[out] dst Where the read data will be stored, must be valid.
/// @param size     The number of bytes to read from the buffer.
///                 Must be lower or equal to <tt>buf->len</tt>.
///
/// @returns A pointer to @c dst.
void *my_cbuffer_read_back(my_cbuffer_t const *buf, void *dst, size_t size);

/// Reads @c size bytes from the start of the circular buffer @c buf plus
/// @c offset.
///
/// @param buf      The buffer, this function assumes that
///                 <tt>bud->data</tt> is a valid memory location.
/// @param[out] dst Where the read data will be stored, must be valid.
/// @param size     The number of bytes to read from the buffer.
///                 Must be lower or equal to <tt>buf->len - offset</tt>.
/// @param offset   The starting offset.
///
/// @returns A pointer to @c dst.
void *my_cbuffer_read_at(
    my_cbuffer_t const *buf, void *dst, size_t size, size_t offset);

/// Removes @c size bytes from the circular buffer @c buf starting from
/// <tt>buf->tail</tt>.
///
/// @param buf      The buffer, this function assumes that
///                 <tt>buf->data</tt> is a valid memory location,
/// @param[out] dst Where the read data will be stored, can be @c NULL.
/// @param size     The number of bytes to read from the buffer.
///                 Must be lower or equal to <tt>buf->len</tt>.
///
/// @returns A pointer to @c dst.
void *my_cbuffer_pop_front(my_cbuffer_t *buf, void *dst, size_t size);

/// Removes a 32-bit ULEB-128 encoded integer from the circular buffer @c buf
/// starting from <tt>buf->tail</tt>.
///
/// @param buf         The buffer, this function assumes that
///                    <tt>buf->data</tt> is a valid memory location.
/// @param[out] output Where the decoded integer is to be written.
///
/// @returns Whether there was enough capacity for the integer.
bool my_cbuffer_pop_front_uleb128_32(
    my_cbuffer_t *restrict buf, uint32_t *restrict output);

/// Removes a 64-bit ULEB-128 encoded integer from the circular buffer @c buf
/// starting from <tt>buf->tail</tt>.
///
/// @param buf         The buffer, this function assumes that
///                    <tt>buf->data</tt> is a valid memory location.
/// @param[out] output Where the decoded integer is to be written.
///
/// @returns Whether there was enough capacity for the integer.
bool my_cbuffer_pop_front_uleb128_64(
    my_cbuffer_t *restrict buf, uint64_t *restrict output);

/// Removes @c size bytes from the circular buffer @c buf starting from
/// <tt>buf->tail</tt> and writes them the given file descriptor.
///
/// @param buf      The buffer, this function assumes that
///                 <tt>buf->data</tt> is a valid memory location.
/// @param fd       The output file descriptor.
///
/// @returns The number of bytes written to @c fd, or -1 on error.
ssize_t my_cbuffer_pop_front_to(my_cbuffer_t *buf, int fd);

/// Removes @c size bytes from the back of the circular buffer @c buf and
/// writes them in @c dst.
///
/// @param buf      The buffer, this function assumes that
///                 <tt>buf->data</tt> is a valid memory location.
/// @param[out] dst Where the read data will be stored, can be @c NULL.
/// @param size     The number of bytes to read from the buffer.
///                 Must be lower or equal to <tt>buf->len</tt>.
///
/// @returns A pointer to @c dst.
void *my_cbuffer_pop_back(my_cbuffer_t *buf, void *dst, size_t size);

/// Writes @c size bytes of the passed memory pointer to the front of the
/// circular buffer @c buf.
///
/// @param buf  The buffer, this function assumes that
///             <tt>buf->data</tt> is a valid memory location.
/// @param src  A pointer to the data to write, must be valid.
/// @param size The number of bytes to write to the buffer's data.
void my_cbuffer_write_front(my_cbuffer_t *buf, void const *src, size_t size);

/// Writes @c size bytes of the passed memory pointer to the circular buffer,
/// starting from <tt>buf->head</tt>.
///
/// @param buf  The buffer, this function assumes that
///             <tt>buf->data</tt> is a valid memory location.
/// @param src  A pointer to the data to write, must be valid.
/// @param size The number of bytes to write to the buffer's data.
void my_cbuffer_write_back(my_cbuffer_t *buf, void const *src, size_t size);

/// Prepends @c size bytes of the passed memory pointer to the front of the
/// circular buffer @c buf.
///
/// @param buf  The buffer, this function assumes that
///             <tt>buf->data</tt> is a valid memory location.
/// @param src  A pointer to the data to write, must be valid.
/// @param size The number of bytes to write to the buffer's data.
void my_cbuffer_push_front(my_cbuffer_t *buf, void const *src, size_t size);

/// Appends @c size bytes of the passed memory pointer to the circular buffer,
/// starting from <tt>buf->head</tt>.
///
/// @param buf  The buffer, this function assumes that
///             <tt>buf->data</tt> is a valid memory location.
/// @param src  A pointer to the data to write, must be valid.
/// @param size The number of bytes to write to the buffer's data.
void my_cbuffer_push_back(my_cbuffer_t *buf, void const *src, size_t size);

/// Appends an ULEB-128 encoded 32 bit int to the circular buffer,
/// starting from <tt>buf->head</tt>.
///
/// @param buf   The buffer, this function assumes that
///              <tt>buf->data</tt> is a valid memory location.
/// @param value The integer to append.
///
/// @return The number of bytes that were added to the buffer, or 0 when not
/// enough capacity.
size_t my_cbuffer_push_back_uleb128_32(my_cbuffer_t *buf, uint32_t value);

/// Appends an ULEB-128 encoded 64 bit int to the circular buffer,
/// starting from <tt>buf->head</tt>.
///
/// @param buf   The buffer, this function assumes that
///              <tt>buf->data</tt> is a valid memory location.
/// @param value The integer to append.
///
/// @return The number of bytes that were added to the buffer, or 0 when not
/// enough capacity.
size_t my_cbuffer_push_back_uleb128_64(my_cbuffer_t *buf, uint64_t value);
/// Rotates the contents of the circular buffer @c amt bytes left.
///
/// @param buf The buffer, this function assumes that
///            <tt>buf->data</tt> is a valid memory location.
/// @param amt The shift amount.
void my_cbuffer_rotate_left(my_cbuffer_t *buf, size_t amt);

/// Rotates the contents of the circular buffer @c amt bytes right.
///
/// @param buf The buffer, this function assumes that
///            <tt>buf->data</tt> is a valid memory location.
/// @param amt The shift amount.
void my_cbuffer_rotate_right(my_cbuffer_t *buf, size_t amt);
