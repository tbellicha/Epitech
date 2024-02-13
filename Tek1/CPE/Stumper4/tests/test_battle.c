/*
** EPITECH PROJECT, 2025
** stump_4
** File description:
** Created by hjulien,
*/

#include <criterion/criterion.h>
#include "pokemon.h"

Test(test_start_fight, pikatchu_raichu)
{
    pokedex_t pokedex;

    pokedex.list_pokemon = malloc(sizeof(pokemon_t) * 2);
    pokedex.nb_pokemon = 2;
    pokedex.list_pokemon[0].name = "Pikatchu";
    pokedex.list_pokemon[0].attack = 42;
    pokedex.list_pokemon[0].defense = 10;
    pokedex.list_pokemon[0].speed = 42;
    pokedex.list_pokemon[0].health = 42;
    pokedex.list_pokemon[1].name = "Raichu";
    pokedex.list_pokemon[1].attack = 84;
    pokedex.list_pokemon[1].defense = 20;
    pokedex.list_pokemon[1].speed = 84;
    pokedex.list_pokemon[1].health = 84;
    start_fight(&pokedex, 0, 1);
    cr_assert_eq(pokedex.list_pokemon[0].health, 0);
}