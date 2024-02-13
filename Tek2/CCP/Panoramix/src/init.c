/*
** EPITECH PROJECT, 2022
** Project
** File description:
** init
*/

#include "pano.h"

druid_t *init_druid(char **argv)
{
    druid_t *druid = malloc(sizeof(druid_t));

    druid->nb_villagers = atoi(argv[1]);
    druid->pot_size = atoi(argv[2]);
    druid->base_pot_size = druid->pot_size;
    druid->nb_fights = atoi(argv[3]);
    druid->nb_refills = atoi(argv[4]);
    return druid;
}