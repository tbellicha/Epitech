/*
** EPITECH PROJECT, 2020
** my_str_isnum
** File description:
** desc
*/

int my_str_isnum(char const *str)
{
    int is_neg = 0;
    int i = 0;

    while (str[i]) {
        if (str[i] == '-')
            is_neg++;
        if (!((str[i] >= 48 && str[i] <= 57) || str[i] == '-') && is_neg > 1)
            return (0);
        i++;
    }
    return (1);
}