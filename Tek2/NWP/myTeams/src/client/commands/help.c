/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** help
*/

#include "client.h"
#include "commands.h"

#include <stdio.h>

void command_help(client_t *client, char *params)
{
    (void)client;
    if (!strcmp(params, "")) {
        print_available_commands();
        return;
    }
    for (int i = 0; commands_infos[i].command != NULL; i++) {
        if (!strcmp(params, commands_infos[i].command)) {
            (*commands_infos[i].print_helper_func)();
            return;
        }
    }
}

void print_helper_help(void)
{
    puts("/help: Display available commands");
}

void print_available_commands(void)
{
    puts("Available commands:");
    puts("\t/help");
    puts("\t/login");
    puts("\t/logout");
    puts("\t/users");
    puts("\t/user");
    puts("\t/send");
    puts("\t/messages");
    puts("\t/subscribe");
    puts("\t/subscribed");
    puts("\t/unsubscribe");
    puts("\t/use");
    puts("\t/create");
    puts("\t/list");
    puts("\t/info");
}
