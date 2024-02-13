/*
** EPITECH PROJECT, 2020
** tests_my_put_isneg.c
** File description:
** 
*/

#include "../../Librairie/include/my.h"

void my_putchar(char c);

int my_put_nbr(int nb);

int main(void)
{
    my_isneg(0);
    my_isneg(2147483647);
    my_isneg(-2147483648);
    my_isneg(-56);
    my_isneg(978);
    return(0);
}
