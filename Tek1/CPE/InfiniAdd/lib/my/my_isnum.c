/*
** EPITECH PROJECT, 2020
** my_isnum
** File description:
** my_isnum
*/

int my_isnum(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}