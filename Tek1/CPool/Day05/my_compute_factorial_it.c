/*
** EPITECH PROJECT, 2020
** my_compute_factorial_it
** File description:
** 
*/

int my_compute_factorial_it(int nb)
{
    int result = 1;

    if (nb < 0 || nb > 12)
        return (0);
    else {
        for (int i = nb; i >= 1; i--) {
            result *= i;
        }
    }
    return (result);
}
