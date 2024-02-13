/*
** EPITECH PROJECT, 2025
** stump_4
** File description:
** Created by hjulien,
*/

#include "pokemon.h"

void display_pokemon_stats(pokemon_t *pokemon)
{
    my_printf("Pokemon %s ", pokemon->name);
    my_printf("has %i attack, ", pokemon->attack);
    my_printf("%i defense, ", pokemon->defense);
    my_printf("%i speed and %i health\n", pokemon->speed, pokemon->health);
}

void display_attack(pokemon_t *attack, pokemon_t *defend, int rand_attack)
{
    int real_heath;

    if (rand_attack > defend->defense)
        real_heath = rand_attack - defend->defense;
    else
        real_heath = 0;
    my_printf("%s attacks for %i damage\n", attack->name, rand_attack);
    my_printf("%s blocks %i damage\n", defend->name, defend->defense);
    my_printf("%s loses ", defend->name);
    my_printf("%i health ", real_heath);
    my_printf("(%i left)\n", defend->health);
}