/*
** EPITECH PROJECT, 2025
** stump_4
** File description:
** Created by hjulien,
*/

#include "pokemon.h"

void pokemon_attack(pokemon_t *pokemon_attack, pokemon_t *pokemon_defend)
{
    int rand_attack = (rand() % pokemon_attack->attack);

    if (rand_attack > pokemon_defend->defense)
        pokemon_defend->health -= rand_attack - pokemon_defend->defense;
    else
        rand_attack = 0;
    if (pokemon_defend->health <= 0)
        pokemon_defend->health = 0;
    display_attack(pokemon_attack, pokemon_defend, rand_attack);
}

void check_ko(pokemon_t *attack, pokemon_t *defend)
{
    if (attack->health <= 0) {
        my_printf("%s is KO\n", attack->name);
        my_printf("%s wins the fight! \n", defend->name);
        exit(EXIT_SUCCESS);
    } else if (defend->health <= 0){
        my_printf("%s is KO\n", defend->name);
        my_printf("%s wins the fight! \n", attack->name);
        exit(EXIT_SUCCESS);
    }
}

void simulate_fight(int index_1, int index_2, pokedex_t *pokedex)
{
    pokemon_t first_pokemon;
    pokemon_t second_pokemon;

    if (pokedex->list_pokemon[index_1].speed > \
    pokedex->list_pokemon[index_2].speed) {
        first_pokemon = pokedex->list_pokemon[index_1];
        second_pokemon = pokedex->list_pokemon[index_2];
    } else {
        first_pokemon = pokedex->list_pokemon[index_2];
        second_pokemon = pokedex->list_pokemon[index_1];
    }
    while (first_pokemon.health && second_pokemon.health) {
        pokemon_attack(&first_pokemon, &second_pokemon);
        check_ko(&first_pokemon, &second_pokemon);
        pokemon_attack(&second_pokemon, &first_pokemon);
    }
    check_ko(&first_pokemon, &second_pokemon);
}

void start_fight(pokedex_t *pokedex, int index_first, int index_second)
{
    for (int i = 0; i < pokedex->nb_pokemon; i++)
        display_pokemon_stats(&pokedex->list_pokemon[i]);
    simulate_fight(index_first, index_second, pokedex);
}