/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** atoi ?
*/

int my_getnbr(char const *str)
{
    int i = 0;
    unsigned int nb = 0;
    int signe = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            signe++;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        nb *= 10;
        nb = nb + (str[i] - 48);
        i++;
    }
    if (nb > 2147483647 && signe % 2 == 0)
        return (0);
    if (nb > 2147483648 && signe % 2 == 1)
        return (0);
    if (signe % 2 == 0)
        return (nb);
    return (nb * -1);
}
