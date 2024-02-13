/*
** EPITECH PROJECT, 2021
** B-PSU-200-NAN-2-1-mysokoban-tanguy.bellicha
** File description:
** main
*/

#include "sokoban.h"
#include "my.h"

void check_endgame(s_soko *soko)
{
    if (check_all_o(soko) == soko->nb_o) {
        display_map(soko);
        endwin();
        exit(0);
    }
    if (!check_all_x(soko)) {
        display_map(soko);
        endwin();
        exit(1);
    }
}

void display_help(void)
{
    my_printf("USAGE\n\t./my_sokoban map\nDESCRIPTION\n\tmap file represen");
    my_printf("ting the warehouse map, containing '#' for walls,\n\t\t'P' ");
    my_printf("for the player, 'X' for boxes and 'O' for storage locations.\n");
    exit(0);
}

int main(int ac, char **av)
{
    s_soko *soko = malloc(sizeof(s_soko));
    char *str;
    int keycode = 0;

    if (av[1] && !my_strcmp(av[1], "-h"))
        display_help();
    if (soko == NULL || ac != 2 || !my_strcmp(str = get_file(av[1]), "Error"))
        return (84);
    initialize_game(soko, str);
    while (1) {
        clear();
        if (is_window_too_small(soko)) {
            display_resize_window_message();
        } else {
            display_map(soko);
            keycode = getch();
            switch_key_code(soko, keycode);
            check_endgame(soko);
        }
    }
}