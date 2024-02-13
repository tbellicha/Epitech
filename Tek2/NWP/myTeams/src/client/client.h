/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** include
*/

#pragma once

#include "client_struct.h"

#include <stdbool.h>
#include <sys/types.h>

enum args_handling { ARGS_VALID, ARGS_HELPER, ARGS_INVALID };

/// Check the arguments of the client.
/// @param argc argc of execution.
/// @param argv argv of execution.
/// @returns args_handling value.
enum args_handling check_args(int argc, char const **argv);

/// Print the helper of the client tcp.
void print_client_help(void);

/// Run the client.
/// @param ip The ip address of the server.
/// @param port The port of the server.
/// @param client A pointer to an empty client structure.
/// @returns false if an error occured.
bool connect_client(char const *ip, char const *port, client_t *client);

/// Initialize the client structure.
/// @param client A pointer to a client structure.
void init_client(client_t *client);

/// Run the client.
/// @param client Client structure that contain all data needed.
/// @returns 0 if success, 84 if error.
int run_client(client_t *client);

/// Remove all duplicated spaces in a string.
/// @param str The string to remove spaces.
char *trim_string(char *str);

/// Check if the string has a pair of double quotes.
/// @param str The string to check.
/// @returns ssize_t The size of the string between the double quotes.
ssize_t parse_string(char *str, char *error_message);

/// Writes the given integer as uleb128 in the file described by @b fd.
///
/// @param fd The file descriptor.
/// @param data The integer to write.
///
/// @returns The number of bytes written, or -1 on error.
ssize_t write_u32(int fd, uint32_t data);

/// Check if a uuid is valid.
/// @param params The string to parse and check.
/// @param error_message The error message to print if an error occurs.
/// @returns -1 if there is an error, length of the uuid otherwise.
ssize_t check_uuid(char *params, char *error_message);

/// Handle select if the fd is on the client set
/// @param client The client structure.
/// @returns false if an error occured.
bool handle_server_select(client_t *client);

/// Handle select if the fd is on the server set
/// @param client The client structure.
/// @returns false if an error occured.
bool handle_client_select(client_t *client);

/// Empty the out cbuffer of the client to send packets to the server.
/// @param client The client structure.
void send_packet(client_t *client);

/// Useful for thread_created.
typedef struct id_path {
    uuid_t creator;
    uuid_t team;
    uuid_t channel;
    uuid_t thread;
    char creator_str[37];
    char thread_str[37];
} id_path_t;

typedef struct reply_created_path {
    uint64_t creation_date;
    uuid_t creator_id;
    uuid_t team_id;
    uuid_t channel_id;
    uuid_t thread_id;
    uuid_t comment_id;
    uint32_t length_before_body;
    char body[513];
} reply_created_path_t;
