/*
** EPITECH PROJECT, 2022
** Project
** File description:
** pano
*/

#ifndef PANO_H_
#define PANO_H_

    #include <stdbool.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <pthread.h>

    #define EXIT_PROG_FAILURE 84
    #define EXIT_PROG_HELPER 0
    #define EXIT_PROG_SUCCESS 0

typedef enum CHECK_ARGS_RETURN {
    CHECK_ARGS_RETURN_OK,
    CHECK_ARGS_RETURN_HELPER,
    CHECK_ARGS_RETURN_ERROR
} CHECK_ARGS_RETURN;

typedef struct druid_s {
    int nb_villagers;
    int pot_size;
    int base_pot_size;
    int nb_fights;
    int nb_refills;
    pthread_mutex_t mutex;
} druid_t;

typedef struct villager_s {
    int id;
    int nb_fights;
    druid_t* druid;
} villager_t;

// -------------------------[ STR_ISNUM.C ] ------------------------- //
bool my_strisnum(char* str);

// -------------------------[ ARGS.C ] ------------------------- //
CHECK_ARGS_RETURN check_args(int argc, char **argv);

// -------------------------[ HELPER.C ] ------------------------- //
void print_helper(void);

// -------------------------[ INIT.C ] ------------------------- //
druid_t *init_druid(char **argv);

// -------------------------[ VILLAGER.C ] ------------------------- //
void* villager_thread(void *param);

// -------------------------[ DRUID.C ] ------------------------- //
void druid_refill(druid_t *druid);

#endif /* !PANO_H_ */
