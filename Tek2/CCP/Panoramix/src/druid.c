/*
** EPITECH PROJECT, 2022
** Project
** File description:
** druid
*/

#include "pano.h"

void druid_refill(druid_t *druid)
{
    printf("Druid: Ah! Yes, yes, I'm awake! Working on it Beware I can only make %d more refills after this one.\n", --druid->nb_refills);
    if (druid->nb_refills > 0) {
        pthread_mutex_lock(&druid->mutex);
        druid->pot_size = druid->base_pot_size;
        druid->nb_refills--;
        pthread_mutex_unlock(&druid->mutex);
    }
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
}