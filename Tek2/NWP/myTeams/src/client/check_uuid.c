/*
** EPITECH PROJECT, 2022
** Project
** File description:
** check_uuid
*/

#include "client.h"
#include "error_messages.h"

#include <stdio.h>
#include <uuid/uuid.h>

ssize_t check_uuid(char *params, char *error_message)
{
    uuid_t target_uuid;
    ssize_t length = parse_string(params, error_message);

    if (length <= 0)
        return -1;
    params++;
    params[length] = '\0';
    if (uuid_parse(params, target_uuid) == -1) {
        puts(error_message);
        return -1;
    }
    return length;
}
