/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Server to client packets
*/

#pragma once

#define MAX_NAME_LENGTH        (32)
#define MAX_DESCRIPTION_LENGTH (255)
#define MAX_BODY_LENGTH        (512)

/// Client to server packet identifier.
typedef enum c2s_packet_id {
    C2S_LOGIN = 0,
    C2S_LOGOUT = 1,
    C2S_GET_USERS = 2,
    C2S_GET_USER_INFO = 3,
    C2S_SEND_MESSAGE = 4,
    C2S_GET_MESSAGES = 5,
    C2S_SUBSCRIBE_TEAM = 6,
    C2S_GET_SUBSCRIBED_TEAMS = 7,
    C2S_GET_TEAM_USERS = 8,
    C2S_UNSUBSCRIBE_TEAM = 9,
    C2S_CREATE_ITEM = 10,
    C2S_GET_TEAMS = 11,
    C2S_GET_CHANNELS = 12,
    C2S_GET_THREADS = 13,
    C2S_GET_COMMENTS = 14,
    C2S_GET_TEAM_INFO = 15,
    C2S_GET_CHANNEL_INFO = 16,
    C2S_GET_THREAD_INFO = 17,
    C2S_SET_CONTEXT = 18,

    // not a packet id
    C2S_PACKET_COUNT,
} c2s_packet_id_t;

/// Server to client packet identifier.
typedef enum s2c_packet_id {
    S2C_GENERIC = 0,
    S2C_LOGIN = 1,
    S2C_LOGOUT = 2,
    S2C_USER_LIST = 3,
    S2C_USER_INFO = 4,
    S2C_MESSAGE_LIST = 5,
    S2C_TEAM_LIST = 6,
    S2C_CHANNEL_LIST = 7,
    S2C_THREAD_LIST = 8,
    S2C_COMMENT_LIST = 9,
    S2C_TEAM_INFO = 10,
    S2C_CHANNEL_INFO = 11,
    S2C_THREAD_INFO = 12,
    S2C_MESSAGE_CREATED = 13,
    S2C_TEAM_CREATED = 14,
    S2C_CHANNEL_CREATED = 15,
    S2C_THREAD_CREATED = 16,
    S2C_COMMENT_CREATED = 17,
    S2C_SUBSCRIBED = 18,
    S2C_UNSUBSCRIBED = 19,
    S2C_UNKNOWN_ITEM = 20,
    S2C_CONTEXT_UPDATE = 21,

    // not a packet id
    S2C_PACKET_COUNT,
} s2c_packet_id_t;

/// Reply codes sent by the server.
typedef enum reply_code {
    REPLY_OK = 0,
    REPLY_INVALID_LENGTH,
    /// Occurs when the client sent too much data, or the client didn't send a
    /// full packet.
    REPLY_TRUNCATION,
    REPLY_INTERNAL_ERROR,
    REPLY_UNKNOWN_PACKET,
    REPLY_NOT_LOGGED_IN,
    /// Sent when the user makes a reference to an unknown user, team, ...
    REPLY_UNKNOWN_TEAM,
    REPLY_UNKNOWN_CHANNEL,
    REPLY_UNKNOWN_THREAD,
    REPLY_UNKNOWN_USER,
    REPLY_ALREADY_EXISTS,

    REPLY_NOT_SUBSCRIBED,
} reply_code_t;

/// Information on where the client/peer is relative to the /use command.
typedef enum {
    CONTEXT_NONE = 0,
    CONTEXT_TEAM,
    CONTEXT_CHANNEL,
    CONTEXT_THREAD,

    /// The number of contexts, not a context by itself.
    CONTEXT_COUNT,
} context_type_t;
