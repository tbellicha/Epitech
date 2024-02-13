/*
** EPITECH PROJECT, 2025
** lib_propre
** File description:
** Created by hjulien,
*/

#include "pokemon.h"

void print_list_pokemon(pokedex_t *pokedex)
{
    int i = 0;

    while (i < pokedex->nb_pokemon) {
        display_pokemon_stats(&pokedex->list_pokemon[i]);
        i++;
    }
}

int main(int ac, char **av)
{
    pokedex_t *pokedex = malloc(sizeof(pokedex_t));

    pokedex->list_pokemon = malloc(sizeof(pokemon_t) * 84);
    if (ac != 3)
        return (84);
    list_files(pokedex, "pokecfg/");
    start_fight(pokedex, find_index_from_name(av[1], pokedex), \
    find_index_from_name(av[2], pokedex));
    return (0);
}