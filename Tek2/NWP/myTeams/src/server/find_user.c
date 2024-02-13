/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** find_user
*/

#include "items/user.h"
#include "server.h"

#include <string.h>
#include <uuid/uuid.h>

user_t *server_find_user_by_name(server_t *server, char const *name)
{
    user_t *user = LIST_FIRST(&server->users);

    while (user) {
        if (strcmp(name, user->name) == 0)
            return user;
        user = LIST_NEXT(user, users);
    }
    return NULL;
}

user_t *server_find_user(server_t *server, uuid_t id)
{
    user_t *user = LIST_FIRST(&server->users);

    while (user) {
        if (uuid_compare(user->id, id) == 0)
            return user;
        user = LIST_NEXT(user, users);
    }
    return NULL;
}
