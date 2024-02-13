/*
** EPITECH PROJECT, 2021
** B-MUL-100-NAN-1-1-myrunner-tanguy.bellicha
** File description:
** check
*/

#include "my.h"
#include "runner.h"

int check_parameters(int argc, char **argv, s_game *game, int display)
{
    if (argc != 2) {
        if (display) {
            write(2, "Bad arguments\n", 15);
            close_all(game);
        }
        return (84);
    }
    if (!my_strcmp(argv[1], "-h")) {
        if (display) {
            my_putstr("Finite runner created with CSFML.\n\nUSAGE\n\t");
            my_putstr("./my_runner map.txt\n\nOPTIONS\n-h\tprint the usage");
            my_putstr(" and quit.\n\nUSER INTERACTIONS\nSPACE_KEY\tJump.\n");
            close_all(game);
        }
        return (0);
    }
    return (1);

}

int check_params_and_map(int argc, char **argv, s_game *game, int display)
{
    if (check_parameters(argc, argv, game, display) != 1)
        return (check_parameters(argc, argv, game, 0));
    if (display)
        game->map = get_file(argv[1]);
    if (!my_strcmp(game->map, "Error") && display == 1) {
        write(2, "Invalid map\n", 12);
        close_all(game);
        return (84);
    }
    return (0);
}

int check_char(char c)
{
    switch (c) {
        case '1':
            return (1);
            break;
        case '2':
            return (1);
            break;
        case '3':
            return (1);
            break;
        case ' ':
            return (1);
        case '\n':
            return (1);
            break;
        default:
            return (0);
    }
}