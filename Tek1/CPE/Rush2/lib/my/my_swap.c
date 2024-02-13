/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** 
*/

void my_swap(int *a, int *b)
{
    int tempo = *a;

    *a = *b;
    *b = tempo;
}
