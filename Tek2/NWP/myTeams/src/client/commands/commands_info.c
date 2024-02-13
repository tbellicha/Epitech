/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** commands
*/

#include "commands.h"

/// Structure of commands, with their names, their helper function and
/// their compute function.
commands_t commands_infos[] = {
    {"help", &print_helper_help, &command_help},
    {"login", &print_helper_login, &command_login},
    {"logout", &print_helper_logout, &command_logout},
    {"users", &print_helper_users, &command_users},
    {"user", &print_helper_user, &command_user},
    {"send", &print_helper_send, &command_send},
    {"messages", &print_helper_messages, &command_messages},
    {"subscribe", &print_helper_subscribe, &command_subscribe},
    {"subscribed", &print_helper_subscribed, &command_subscribed},
    {"unsubscribe", &print_helper_unsubscribe, &command_unsubscribe},
    {"use", &print_helper_use, &command_use},
    {"create", &print_helper_create, &command_create},
    {"list", &print_helper_list, &command_list},
    {"info", &print_helper_info, &command_info},
    {NULL, NULL, NULL},
};
