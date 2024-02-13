/*
** EPITECH PROJECT, 2022
** Project
** File description:
** villager
*/

#include "pano.h"

void* villager_thread(void *param)
{
    villager_t *villager = (villager_t *)param;
    druid_t *druid = villager->druid;

    if (villager == NULL || druid == NULL)
        return NULL;
    printf("Villager %d: Going into battle!\n", villager->id);
    while (villager->nb_fights >= 0) {
        pthread_mutex_lock(&druid->mutex);
        printf("Villager %d: I need a drink... I see %d servings left.\n",
            villager->id, druid->pot_size);
        if (druid->pot_size == 0) {
            printf("Villager %d: Hey Pano wake up! We need more potion.\n",
                villager->id);
            druid_refill(druid);
        } else
            druid->pot_size--;
        pthread_mutex_unlock(&druid->mutex);
        printf("Villager %d: Take that roman scum! Only %d left.\n",
            villager->id, villager->nb_fights--);
    }
    printf("Villager %d: I'm going to sleep now.\n", villager->id);
    return NULL;
}