/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** desc
*/

void my_swap(char **str1, char **str2)
{
    char *tempo = *str1;

    *str1 = *str2;
    *str2 = tempo;
}
