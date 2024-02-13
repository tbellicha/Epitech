/*
** EPITECH PROJECT, 2022
** Project
** File description:
** main
*/

#include "pano.h"

int compute(druid_t *druid)
{
    villager_t villagers[druid->nb_villagers];
    pthread_t threads[druid->nb_villagers];

    if (villagers == NULL || threads == NULL)
        return (EXIT_PROG_FAILURE);
    pthread_mutex_init(&druid->mutex, NULL);
    for (int i = 0; i < druid->nb_villagers; i++) {
        villagers[i].id = i;
        villagers[i].nb_fights = druid->nb_fights;
        villagers[i].druid = druid;
        pthread_create(&threads[i], NULL, &villager_thread, &villagers[i]);
    }
    for (int i = 0; i < druid->nb_villagers; ++i) {
        pthread_join(threads[i], NULL);
    }
    return (EXIT_PROG_SUCCESS);
}

int main(int argc, char **argv)
{
    druid_t *druid = malloc(sizeof(druid_t));

    if (druid == NULL)
        return EXIT_PROG_FAILURE;
    switch (check_args(argc, argv)) {
    case CHECK_ARGS_RETURN_ERROR:
        print_helper();
        printf("Values must be >0.\n");
        return (EXIT_PROG_FAILURE);
    case CHECK_ARGS_RETURN_HELPER:
        print_helper();
        return (EXIT_PROG_HELPER);
    case CHECK_ARGS_RETURN_OK:
        druid = init_druid(argv);
        break;
    }
    return compute(druid);
}