/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper3-tanguy.bellicha
** File description:
** options
*/

#include "proto.h"

int get_occurence_in_string(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            count++;
    }
    return (count);
}

char *my_get_string_until(char *str, char end_char)
{
    int i = 0;
    char *final_str = NULL;

    while (str[i] && str[i] != end_char)
        i++;
    final_str = malloc(sizeof(char) * i);
    i = 0;
    while (str[i] && str[i] != end_char) {
        final_str[i] = str[i];
        i++;
    }
    final_str[i + 1] = 0;
    return (my_strncpy(final_str, str, i));
}

int check_flag(char *flag)
{
    if (!my_strcmp(flag, "-f") || !my_strcmp(flag, "--fields"))
        return ('f');
    if (!my_strcmp(flag, "-c") || !my_strcmp(flag, "--characters"))
        return ('c');
    if (!my_strcmp(flag, "-d") || !my_strcmp(flag, "--delimiter"))
        return ('d');
    return (0);
}

struct minicut check_combinaison_of_flag(struct minicut infos)
{
    if (infos.delimiter != '\t' && infos.act_op == 'c') {
        my_putstr("./minicut: an input delimeter may be specified ");
        my_putstr("only when operating on fields\n");
        infos.ret = 84;
    }
    if (infos.act_op == 'f' || infos.act_op == 'c') {
        my_putstr("./minicut: only one type of list may be specified\n");
        infos.ret = 84;
    }
    return (infos);
}

struct minicut parse_options(char **argv, struct minicut infos)
{
    int flag = check_flag(argv[0]);

    if (flag == 'c' || flag == 'f') {
        if ((infos = check_combinaison_of_flag(infos)).ret == 84)
            return (infos);
        infos.act_op = flag;
        infos.lines = malloc(sizeof(char *) * \
        (get_occurence_in_string(argv[1], ',') + 1));
        for (int i = 0; i < my_strlen(argv[1]);) {
            infos.lines[infos.nb_line] = malloc(sizeof(char) * \
            my_strlen(my_get_string_until(&argv[1][i], ',')));
            infos.lines[infos.nb_line] = my_get_string_until(&argv[1][i], ',');
            i += my_strlen(infos.lines[infos.nb_line]) + 1;
            infos.nb_line++;
        }
    } else if (flag == 'd') {
        if (infos.act_op == 'c') {
            infos.ret = 84;
            return (infos);
        }
        infos.delimiter = argv[1][0];
    }
    else
        infos.ret = 84;
    return (infos);
}