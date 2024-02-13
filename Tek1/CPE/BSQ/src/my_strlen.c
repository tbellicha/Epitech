/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-BSQ-tanguy.bellicha
** File description:
** my_strlen
*/

int	my_strlen(char *str)
{
    int	i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

int	get_horizontal_length(char *str, int i)
{
    while (str[i] != '\n')
        i++;
    return (i);
}