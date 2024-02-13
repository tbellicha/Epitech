/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myls-tanguy.bellicha
** File description:
** cd lib/my/ && make re && cd ../.. && clear && make re && make clean && ./my_
*/

#include "my.h"

s_my_ls reset_params(void)
{
    s_my_ls params;

    params.lsr = 0;
    params.lsR = 0;
    params.lsl = 0;
    params.lst = 0;
    params.lsd = 0;
    params.valid = 1;
    return (params);
}

void do_lsd(s_my_ls params, char **argv, int i)
{
    while (params.lsd == 1 && params.valid == 1 && \
    (get_type(argv[i]) || !argv[i + 1])) {
        if (get_type(argv[i])) {
            my_printf("%s\n", argv[i]);
            return ;
        }
        if (!argv[i + 1]) {
            my_printf(".\n");
            return ;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    int i = 1;
    s_my_ls params;

    if (argc == 1)
        return (my_ls_without_flag(opendir("./")));
    params = reset_params();
    while (argv[i]) {
        if (get_type(argv[i]) == 0)
            params = detect_flags(params, argv[i]);
        else if (print_error_access(get_type(argv[i]), argv[i]) != 1)
            return (84);
        do_lsd(params, argv, i);
        if (get_type(argv[i])) {
            display_result(argv[i], params);
            params = reset_params();
        }
        i++;
    }
    return (0);
}
//Mettre aux normes
//Mieux gérer les mallocs
//./my_ls -d [fichier] doesn't works
//./my_ls -ld doit donner les infos sur le dossier
//./my_ls -l src/ -l include/