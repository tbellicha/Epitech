/*
** EPITECH PROJECT, 2020
** tests_my_put_nbr.c
** File description:
** 
*/

void my_putchar(char c);

int my_put_nbr(int nb);

int main(void)
{
    my_put_nbr(0);
    my_put_nbr(2147483647);
    my_put_nbr(-2147483648);
    my_put_nbr(-56);
    my_put_nbr(978);
    return(0);
}
