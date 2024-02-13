/*
** EPITECH PROJECT, 2020
** do_op
** File description:
** desc
*/

#include <stdio.h>
#include "my.h"
#include <unistd.h>

int add(int nb1, int nb2);

int sub(int nb1, int nb2);

int multi(int nb1, int nb2);

int divide(int nb1, int nb2);

int mdlo(int nb1, int nb2);

int do_op(int nb1, char operator, int nb2)
{
    int result = 0;
    int (*function[5])(int, int) = {&add, &sub, &multi, &divide, &mdlo};
    char list_operators[5] = {'+', '-', '*', '/', '%'};

    for (int i = 0; i < 5; i++)
        if (list_operators[i] == operator) {
            result = function[i](nb1, nb2);
            break;
        }
    my_put_nbr(result);
    return (result);
}

int main(int argc, char **argv)
{
    int nb1;
    int nb2;
    char operator;

    if (argc != 4)
        return (84);
    if (argv[2][0] == '/' && my_getnbr(argv[3]) == 0) {
        write(2, "Stop: division by zero", 22);
        return (84);
    }
    if (argv[2][0] == '%' && my_getnbr(argv[3]) == 0) {
        write(2, "Stop: modulo by zero", 20);
        return (84);
    }
    nb1 = my_getnbr(argv[1]);
    nb2 = my_getnbr(argv[3]);
    operator = argv[2][0];
    do_op(nb1, operator, nb2);
}
