/*
** EPITECH PROJECT, 2020
** my_params_to_array
** File description:
** desc
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"

struct info_param *my_params_to_array(int ac, char **av)
{
    struct info_param *infos_prm = malloc(sizeof(struct info_param) * (ac + 1));
    int i = 0;

    if (infos_prm == 0)
        return (0);
    for (i = 0; i < ac; i++) {
        infos_prm[i].length = my_strlen(av[i]);
        infos_prm[i].str = av[i];
        infos_prm[i].copy = my_strdup(av[i]);
        infos_prm[i].word_array = my_str_to_word_array(av[i]);
    }
    infos_prm[i + 1].str = 0;
    return (infos_prm);
}
