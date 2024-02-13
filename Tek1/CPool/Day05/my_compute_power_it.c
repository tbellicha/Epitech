/*
** EPITECH PROJECT, 2020
** my_compute_power_it
** File description:
** 
*/

int my_compute_power_it(int nb, int p)
{
    int result;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    else if (p == 1)
        return (nb);
    result = nb;
    for (int i = 0; i < p - 1; i++)
        result *= nb;
    return (result);
}
