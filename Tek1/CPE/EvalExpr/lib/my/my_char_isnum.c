/*
** EPITECH PROJECT, 2020
** my_char_isnum
** File description:
** desc
*/

int my_str_isnum(char const *str)
{
    if (str >= 48 && str <= 57)
        return (1);
    else
        return (0);
}