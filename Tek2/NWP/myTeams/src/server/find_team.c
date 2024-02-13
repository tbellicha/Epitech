/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** find_team
*/

#include "items/team.h"
#include "server.h"

#include <string.h>

team_t *server_find_team(server_t const *server, uuid_t id)
{
    team_t *t = LIST_FIRST(&server->teams);

    while (t) {
        if (uuid_compare(id, t->header.id) == 0)
            return t;
        t = LIST_NEXT(t, teams);
    }
    return NULL;
}

team_t *server_find_team_by_name(server_t const *server, char const *name)
{
    team_t *t = LIST_FIRST(&server->teams);

    while (t) {
        if (strcmp(name, t->name) == 0)
            return t;
        t = LIST_NEXT(t, teams);
    }
    return NULL;
}
