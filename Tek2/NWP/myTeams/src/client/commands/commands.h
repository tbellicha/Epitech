/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** include
*/

#pragma once

#include "client_struct.h"

#include <stdio.h>
#include <string.h>

#define COMMANDS_PREFIX '/'

typedef struct commands {
    char *command;
    void (*print_helper_func)(void);
    void (*func)(client_t *client, char *params);
} commands_t;

/* commands_info.c */
extern commands_t commands_infos[];

/* handle_command.c */
void handle_command(client_t *client, char *input);

/* help.c */
/// Display the helper of a given command or list all commands.
/// @param client Client structure.
/// @param params The parameters of the command.
void command_help(client_t *client, char *input);
/// Print helper of the helper command.
void print_helper_help(void);
/// Print available commands.
void print_available_commands(void);

/* login.c */
/// Set the user_name used by client.
/// @param client Client structure.
/// @param params The parameters of the command.
void command_login(client_t *client, char *input);
/// Print helper of the login command.
void print_helper_login(void);

/* logout.c */
/// Disconnect the client from the server.
/// @param client Client structure.
/// @param params The parameters of the command.
void command_logout(client_t *client, char *input);
/// Print helper of the logout command.
void print_helper_logout(void);

/* users.c */
void command_users(client_t *client, char *input);
void print_helper_users(void);

/* user.c */
/// Get information about a user.
/// @param client Client structure.
/// @param params The parameters of the command.
void command_user(client_t *client, char *input);
/// Print helper of the user command.
void print_helper_user(void);

/* send.c */
/// Send a message to a user.
/// @param client Client structure.
/// @param params The parameters of the command.
void command_send(client_t *client, char *input);
/// Print helper of the send command.
void print_helper_send(void);

/* messages.c */
/// List all messages exchange with an user.
/// @param client Client structure.
/// @param params The parameters of the command.
void command_messages(client_t *client, char *input);
/// Print helper of the messages command.
void print_helper_messages(void);

/* subscribe.c */
/// Subscribe to the event of a team.
/// @param client Client structure.
/// @param params The parameters of the command.
void command_subscribe(client_t *client, char *input);
/// Print helper of the subscribe command.
void print_helper_subscribe(void);

/* subscribed.c */
/// List all subscribed teams or list all users subscribed to a team.
/// @param client Client structure.
/// @param params The parameters of the command.
void command_subscribed(client_t *client, char *input);
/// Print helper of the subscribed command.
void print_helper_subscribed(void);

/* unsubscribe.c */
/// Unsubscribe from a team.
/// @param client Client structure.
/// @param params The parameters of the command.
void command_unsubscribe(client_t *client, char *input);
/// Print helper of the unsubscribe command.
void print_helper_unsubscribe(void);

/* use.c */
/// Change the context of the client.
/// @param client Client structure.
/// @param params The parameters of the command.
void command_use(client_t *client, char *input);
/// Print helper of the use command.
void print_helper_use(void);

/* create.c */
/// Create a team/channel/thread/comment depending on the context.
/// @param client Client structure.
/// @param params The parameters of the command.
void command_create(client_t *client, char *input);
/// Print helper of the create command.
void print_helper_create(void);

/* list.c */
/// Display the list of existing team/channel/thread/comment depending on the
/// context.
/// @param client Client structure.
/// @param params The parameters of the command.
void command_list(client_t *client, char *input);
/// Print helper of the list command.
void print_helper_list(void);

/* info.c */
/// Display informations on the team/channel/thread/comment depending on the
/// context.
/// @param client Client structure.
/// @param params The parameters of the command.
void command_info(client_t *client, char *input);
/// Print helper of the info command.
void print_helper_info(void);
