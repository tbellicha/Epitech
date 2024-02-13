/*
** EPITECH PROJECT, 2020
** my_isalpha.c
** File description:
** is a letter
*/

int my_isalpha(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (1);
    return (0);
}
