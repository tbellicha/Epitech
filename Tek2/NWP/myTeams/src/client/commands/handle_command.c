/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** command
*/

#include "commands.h"

/// Run the command corresponding to the given index.
/// @param i Index of the command.
/// @param params Parameters for the given command.
/// @param sock_fd The socket of the server.
void run_command(int i, char *params, client_t *client)
{
    if (params == NULL)
        (*commands_infos[i].func)(client, "");
    else
        (*commands_infos[i].func)(client, params);
}

/// Parse the input and run the corresponding command.
/// @param sock_fd The socket of the server.
/// @param input The input from the client.
void handle_command(client_t *client, char *input)
{
    char *command_input = strtok(input, " ");
    char *params = strtok(NULL, "\n");

    if (command_input == NULL)
        return;
    if (input[0] && input[0] != COMMANDS_PREFIX) {
        puts("Not a command.");
        return;
    }
    for (size_t i = 0; commands_infos[i].command != NULL; i++) {
        if (!strcmp(&command_input[1], commands_infos[i].command)) {
            run_command(i, params, client);
            return;
        }
    }
    printf("%s: Unknown command.\n", command_input);
}
