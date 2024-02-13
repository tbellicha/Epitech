/*
** EPITECH PROJECT, 2025
** stump_4
** File description:
** Created by hjulien,
*/

#include "pokemon.h"

int find_index_from_name(char *name, pokedex_t *pokedex)
{
    int i;

    for (i = 0; i < pokedex->nb_pokemon; i++)
        if (!my_strcmp(name, pokedex->list_pokemon[i].name))
            return (i);
    my_putstr_err("Pokemon ");
    my_putstr_err(name);
    my_putstr_err(" doesn't exists\n");
    exit(EXIT_ERROR);
}